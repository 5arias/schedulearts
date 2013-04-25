<?php

/**
 * Form callback for listing all existing reorders.
 */
function form_dropdown_reorder_list_form($form, $form_state) {
  $headers = array(t('Rule'), t('Append'), '');
  $rows = array();
  $res = db_select('form_dropdown_reorder', 'f')
    ->fields('f')
    ->execute();
  if ($res->rowCount()) {
    while ($row = $res->fetchAssoc()) {
      $rows[] = array(
        l($row['form_id'] . ':' . $row['form_element'], 'admin/config/user-interface/form-dropdown-reorder/'.$row['fdrid']),
        $row['append'] ? t('Yes') : t('No'),
        l('delete', 'admin/config/user-interface/form-dropdown-reorder/delete/'.$row['fdrid']),
      );
    }
    $form['list'] = array(
      '#theme' => 'table',
      '#header' => $headers,
      '#rows' => $rows,
    );
  }
  $form['new'] = array(
    '#markup' => '<strong>Insert new ordering override:</strong>',
  );
  $form['formid'] = array(
    '#type' => 'textfield',
    '#title' => t('Form ID'),
    '#required' => TRUE,
    '#description' => t('The Drupal form ID of the form being altered.'),
  );
  $form['formelement'] = array(
    '#type' => 'textfield',
    '#title' => t('Form element'),
    '#required' => TRUE,
    '#description' => t('The Drupal name of the element being altered.'),
  );
  $form['append'] = array(
    '#type' => 'checkbox',
    '#title' => t('Append'),
    '#description' => t('If checked, elements without an assigned weight are appended to the list, otherwise, they are prepended.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Add override',
  );
  $form['#validate'][] = 'form_dropdown_reorder_list_form_validate';
  $form['#submit'][] = 'form_dropdown_reorder_list_form_submit';
  return $form;
}

function form_dropdown_reorder_list_form_validate($form, &$form_state) {
  $res = db_select('form_dropdown_reorder', 'f')
    ->fields('f')
    ->condition('form_id', $form_state['values']['formid'])
    ->condition('form_element', $form_state['values']['formelement'])
    ->execute()
    ->rowCount();
  if ($res > 0) {
    form_set_error('formid', t('The specified form ID - element pair already exists.'));
    form_set_error('formelement');
  }
}

function form_dropdown_reorder_list_form_submit($form, &$form_state) {
  db_insert('form_dropdown_reorder')
    ->fields(array(
      'form_id' => $form_state['values']['formid'],
      'form_element' => $form_state['values']['formelement'],
      'append' => $form_state['values']['append'] ? 1 : 0,
    ))
    ->execute();
  $id = db_select('form_dropdown_reorder', 'f')
    ->fields('f', array('fdrid'))
    ->condition('form_id', $form_state['values']['formid'])
    ->condition('form_element', $form_state['values']['formelement'])
    ->execute()
    ->fetchField();
  $form_state['redirect'] = 'admin/config/user-interface/form-dropdown-reorder/'.$id;
}

function form_dropdown_reorder_view($reorder) {
  return theme('form_dropdown_reorder_manage',
               array('form' => drupal_get_form('form_dropdown_reorder_manage', $reorder['fdrid']),
                                               'reorder' => $reorder));
}

function form_dropdown_reorder_manage($form, $form_state, $fdrid) {
  $form = array();
  $form['#tree'] = TRUE;
  $res = db_select('form_dropdown_reorder_weights', 'f')
    ->fields('f')
    ->condition('fdrid', $fdrid)
    ->orderBy('weight', 'ASC')
    ->execute();
  if ($res->rowCount()) {
    $form['#rowcount'] = $res->rowCount();
    while ($row = $res->fetchAssoc()) {
      $form['rows'][$row['fwid']]['key'] = array(
        '#type' => 'item',
        '#markup' => '<strong>'.$row['mkey'].'</strong>'
      );
      $form['rows'][$row['fwid']]['weight'] = array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#title_display' => 'invisible',
        '#default_value' => $row['weight'],
      );
      $form['rows'][$row['fwid']]['op'] = array(
        '#markup' => l(t('delete'), 'admin/config/user-interface/form-dropdown-reorder/'.$row['fdrid'].'/remove/'.$row['fwid']),
      );
    }
    $form['table'] = array();
    $form['save'] = array(
      '#type' => 'submit',
      '#name' => 'saver',
      '#value' => t('Save changes'),
    );
  } else {
    $form['#rowcount'] = 0;
  }
  $form['#fdrid'] = $fdrid;
  $form['add'] = array(
    '#markup' => '<br/><strong>'.t('Add new key/weight pair').'</strong>',
  );
  $form['key'] = array(
    '#type' => 'textfield',
    '#title' => t('Option key'),
    '#description' => t('The HTML key of the option being altered.'),
  );
  $form['weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Weight'),
    '#description' => t('The weight of the option being altered.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#name' => 'adder',
    '#value' => t('Add option'),
  );
  $form['#validate'][] = 'form_dropdown_reorder_manage_validate';
  $form['#submit'][] = 'form_dropdown_reorder_manage_submit';
  return $form;
}

function form_dropdown_reorder_manage_validate($form, &$form_state) {
  if ($form_state['triggering_element']['#name'] == 'adder') {
    if ($form_state['values']['key'] == '') {
      form_set_error('key', t('Key is required.'));
      return;
    }
    if ($form_state['values']['weight'] == '') {
      form_set_error('weight', t('Weight is required.'));
      return;
    }
    $res = db_select('form_dropdown_reorder_weights', 'f')
      ->fields('f')
      ->condition('fdrid', $form['#fdrid'])
      ->condition('mkey', $form_state['values']['key'], '=')
      ->execute()
      ->rowCount();
    if ($res > 0) {
      form_set_error('key', t('The specified form ID - element - option key pair already exists.'));
    }
    if (!is_numeric($form_state['values']['weight'])) {
      form_set_error('weight', t('The weight must be numeric!'));
    }
  }
}

function form_dropdown_reorder_manage_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#name'] == 'adder') {
    db_insert('form_dropdown_reorder_weights')
      ->fields(array(
                    'fdrid' => $form['#fdrid'],
                    'mkey' => $form_state['values']['key'],
                    'weight' => $form_state['values']['weight'],
               ))
      ->execute();
  }
  else {
    drupal_set_message(print_r($_REQUEST, true));
    foreach ($form_state['values']['rows'] as $fwid => $warr) {
      drupal_set_message('updating ' . $fwid . ' to ' . print_r($warr, true));
      db_update('form_dropdown_reorder_weights')
        ->fields(array('weight' => $warr['weight']))
        ->condition('fwid', $fwid)
        ->execute();
    }
  }
}

function theme_form_dropdown_reorder_manage($variables) {
  $reorder = $variables['reorder'];
  $form = $variables['form'];
  $fdrid = $reorder['fdrid'];
  $output = '';
  if ($form['#rowcount']) {
    $rows = array();
    foreach (element_children($form['rows']) as $fwid) {
      $form['rows'][$fwid]['weight']['#attributes']['class'] = array('reorder-weights');
      $rows[] = array(
        'data' => array(
          array('class' => array('reorder-cross')),
          drupal_render($form['rows'][$fwid]['key']),
          drupal_render($form['rows'][$fwid]['weight']),
          drupal_render($form['rows'][$fwid]['op']),
        ),
        'class' => array('draggable'),
      );
    }
    $header = array('', t('Key'), t('Weight'), t('Operations'));
    $form['table'] = array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#attributes' => array('id' => 'rows-order'),
    );
    //$output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'rows-order')));
  }
  $output .= drupal_render($form);
  if ($form['#rowcount'])
    drupal_add_tabledrag('rows-order', 'order', 'sibling', 'reorder-weights');
  return $output;
}

function form_dropdown_reorder_remove_option($reorder, $opt) {
  db_delete('form_dropdown_reorder_weights')
    ->condition('fwid', $opt, '=')
    ->condition('fdrid', $reorder['fdrid'], '=')
    ->execute();
  drupal_goto('admin/config/user-interface/form-dropdown-reorder/' . $reorder['fdrid']);
}

function form_dropdown_reorder_confirm_delete($form, $form_state, $reorder) {
  if (!$reorder) {
    drupal_set_message('Invalid ID!', 'error');
    drupal_goto('admin/config/user-interface/form-dropdown-reorder');
  }
  $form['#fdrid'] = $reorder['fdrid'];
  $form['#submit'][] = 'form_dropdown_reorder_confirm_delete_submit';
  return confirm_form($form, t('Are you sure you want to delete the reorder rule !rule?',
                      array('!rule' => $reorder['form_id'] . ':' . $reorder['form_element'])),
                      'admin/config/user-interface/form-dropdown-reorder');
}

function form_dropdown_reorder_confirm_delete_submit($form, &$form_state) {
  db_delete('form_dropdown_reorder_weights')
    ->condition('fdrid', $form['#fdrid'])
    ->execute();
  drupal_goto('admin/config/user-interface/form-dropdown-reorder');
}
