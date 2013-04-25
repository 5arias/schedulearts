<?php
/**
 * @file
 * schedulearts_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function schedulearts_rules_default_rules_configuration() {
  $items = array();
  $items['rules_cache_user_name_and_email_in_searchable_name'] = entity_import('rules_config', '{ "rules_cache_user_name_and_email_in_searchable_name" : {
      "LABEL" : "cache user name and email in searchable_name",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_presave" ],
      "DO" : [
        { "data_set" : {
            "data" : [ "account:field-user-searchable-name" ],
            "value" : "[account:field-user-fname] [account:field-user-lname] - [account:mail]"
          }
        }
      ]
    }
  }');
  $items['rules_clear_menu_cache_for_new_roles'] = entity_import('rules_config', '{ "rules_clear_menu_cache_for_new_roles" : {
      "LABEL" : "clear menu cache for new roles",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "php" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "NOT data_is" : { "data" : [ "account-unchanged:roles" ], "value" : [ "account:roles" ] } }
      ],
      "DO" : [
        { "php_eval" : { "code" : "cache_clear_all($account-\\u003Euid .\\u0027:\\u0027, \\u0027cache_menu\\u0027, TRUE);" } }
      ]
    }
  }');
  $items['rules_copy_production_color_to_master_event'] = entity_import('rules_config', '{ "rules_copy_production_color_to_master_event" : {
      "LABEL" : "Copy production color to master event",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_presave" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "master_calendar_event" : "master_calendar_event" } }
          }
        },
        { "entity_is_of_type" : { "entity" : [ "node:field-production" ], "type" : "node" } }
      ],
      "DO" : [
        { "component_rules_update_mc_event_color" : { "production" : [ "node:field-production" ], "event" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_delete_dependent_calls_on_event_deletion'] = entity_import('rules_config', '{ "rules_delete_dependent_calls_on_event_deletion" : {
      "LABEL" : "Delete dependent calls on event deletion",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_delete" ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_call_parent_event",
              "value" : [ "node:nid" ],
              "limit" : "100"
            },
            "PROVIDE" : { "entity_fetched" : { "related_calls" : "related calls" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "related-calls" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [ { "entity_delete" : { "data" : [ "list-item" ] } } ]
          }
        }
      ]
    }
  }');
  $items['rules_delete_soft_resource_conflicts_presave'] = entity_import('rules_config', '{ "rules_delete_soft_resource_conflicts_presave" : {
      "LABEL" : "delete soft resource conflicts pre-save",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "conflict detection" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_presave" ],
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "node:nid" ] } } ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_conflict_grp_call",
              "value" : [ "node:nid" ],
              "limit" : "999"
            },
            "PROVIDE" : { "entity_fetched" : { "group_conflicts" : "group conflicts" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-conflicts" ] },
            "ITEM" : { "current_group_conflict" : "Current group conflict" },
            "DO" : [ { "entity_delete" : { "data" : [ "current-group-conflict" ] } } ]
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_conflict_ind_call",
              "value" : [ "node:nid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "individual_conflicts" : "individual conflicts" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "individual-conflicts" ] },
            "ITEM" : { "current_individual_conflict" : "Current individual conflict" },
            "DO" : [ { "entity_delete" : { "data" : [ "current-individual-conflict" ] } } ]
          }
        }
      ]
    }
  }');
  $items['rules_demote_from_company_administrator'] = entity_import('rules_config', '{ "rules_demote_from_company_administrator" : {
      "LABEL" : "Demote from company administrator",
      "PLUGIN" : "action set",
      "TAGS" : [ "VBO actions" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "user", "type" : "user" } },
      "ACTION SET" : [
        { "user_remove_role" : { "account" : [ "user" ], "roles" : { "value" : { "4" : "4" } } } }
      ]
    }
  }');
  $items['rules_detect_group_hard_conflicts'] = entity_import('rules_config', '{ "rules_detect_group_hard_conflicts" : {
      "LABEL" : "Detect group hard conflicts",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "flag", "php" ],
      "USES VARIABLES" : {
        "current_conflict_list_item_group" : { "label" : "Current conflict group", "type" : "taxonomy_term" },
        "saved_node_group_item" : { "label" : "Saved node group", "type" : "taxonomy_term" },
        "saved_node" : { "label" : "Saved node", "type" : "node" },
        "current_conflicts_list_item" : { "label" : "Current conflict node", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "current-conflict-list-item-group" ],
            "value" : [ "saved-node-group-item" ]
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "conflict",
              "param_title" : "[current-conflict-list-item-group:name] is called to both [saved-node:title] and [current-conflicts-list-item:title] ",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "conflict_entity_created" : "Created conflict entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "conflict-entity-created:field-conflict-grp-call" ],
            "value" : [ "current-conflicts-list-item" ]
          }
        },
        { "data_set" : {
            "data" : [ "conflict-entity-created:field-conflict-ind-call" ],
            "value" : [ "saved-node" ]
          }
        },
        { "data_set" : {
            "data" : [ "conflict-entity-created:field-conflict-group" ],
            "value" : [ "current-conflict-list-item-group" ]
          }
        },
        { "entity_save" : { "data" : [ "conflict-entity-created" ], "immediate" : 1 } },
        { "flag_flagnode" : {
            "flag" : "hard_conflict",
            "node" : [ "conflict-entity-created" ],
            "flagging_user" : "1",
            "permission_check" : 0
          }
        },
        { "drupal_message" : {
            "message" : "\\u003Cstrong\\u003ECONFLICT:\\u003C\\/strong\\u003E \\u003C?php \\r\\nif(isset($conflict_entity_created-\\u003Efield_conflict_usr[\\u0027und\\u0027])) { \\r\\n  $conflict_object = user_load($conflict_entity_created-\\u003Efield_conflict_usr[\\u0027und\\u0027][\\u00270\\u0027][\\u0027target_id\\u0027]);\\r\\n  $conflict_fname_dirty = field_get_items(\\u0027user\\u0027, $conflict_object, \\u0027field_user_fname\\u0027);\\r\\n  $conflict_lname_dirty = field_get_items(\\u0027user\\u0027, $conflict_object, \\u0027field_user_lname\\u0027);\\r\\n  $conflict_fname = field_view_value(\\u0027user\\u0027, $conflict_object, \\u0027field_user_fname\\u0027, $conflict_fname_dirty[0]);\\r\\n  $conflict_lname = field_view_value(\\u0027user\\u0027, $conflict_object, \\u0027field_user_lname\\u0027, $conflict_lname_dirty[0]);\\r\\n  $conflict_name = $conflict_fname[\\u0027#markup\\u0027] . \\u0027 \\u0027 . $conflict_lname[\\u0027#markup\\u0027];\\r\\n  $conflict_path = entity_uri(\\u0027user\\u0027, $conflict_object);\\r\\n  $conflict_object_link = l($conflict_name, $conflict_path[\\u0027path\\u0027]);\\r\\n} \\r\\nelseif(isset($conflict_entity_created-\\u003Efield_conflict_group[\\u0027und\\u0027])) {\\r\\n  $conflict_object = taxonomy_term_load($conflict_entity_created-\\u003Efield_conflict_group[\\u0027und\\u0027][\\u00270\\u0027][\\u0027tid\\u0027]);\\r\\n  $conflict_name = $conflict_object-\\u003Ename;\\r\\n  $conflict_path = entity_uri(\\u0027taxonomy_term\\u0027, $conflict_object);\\r\\n  $conflict_object_link = l($conflict_name, $conflict_path[\\u0027path\\u0027]);\\r\\n} \\r\\nprint $conflict_object_link;\\r\\n?\\u003E is scheduled for \\u003Ca href=\\u0022[conflict-entity-created:field-conflict-grp-call:url]\\u0022\\u003E[conflict-entity-created:field-conflict-grp-call:title]\\u003C\\/a\\u003E and \\u003Ca href=\\u0022[conflict-entity-created:field-conflict-ind-call:url]\\u0022\\u003E[conflict-entity-created:field-conflict-ind-call:title]\\u003C\\/a\\u003E at the same time. \\u003Cspan class=\\u0022conflict-msg-buttons\\u0022\\u003E\\u003C?php print flag_create_link(\\u0027conflict_approved\\u0027, $conflict_entity_created-\\u003Enid); ?\\u003E \\u003C?php print flag_create_link(\\u0027conflict_postponed\\u0027, $conflict_entity_created-\\u003Enid); ?\\u003E\\u003C\\/span\\u003E\\r\\n\\r\\n",
            "type" : "error",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  $items['rules_detect_group_parent_soft_conflicts'] = entity_import('rules_config', '{ "rules_detect_group_parent_soft_conflicts" : {
      "LABEL" : "Detect group parent soft conflicts",
      "PLUGIN" : "rule",
      "TAGS" : [ "conflict detection" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "parent_term" : { "label" : "parent_term", "type" : "taxonomy_term" },
        "term_list" : { "label" : "term_list", "type" : "list\\u003Ctaxonomy_term\\u003E" },
        "conflict_node" : { "label" : "parent_node", "type" : "node" },
        "term" : { "label" : "term", "type" : "taxonomy_term" },
        "node" : { "label" : "node", "type" : "node" }
      },
      "IF" : [
        { "list_contains" : { "list" : [ "term-list" ], "item" : [ "parent-term" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "conflict",
              "param_title" : "[term:name] is called to both [node:title] and [conflict-node:title]",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "created_conflict_record" : "Created conflict record" } }
          }
        },
        { "data_set" : {
            "data" : [ "created-conflict-record:field-conflict-grp-call" ],
            "value" : [ "conflict-node" ]
          }
        },
        { "data_set" : {
            "data" : [ "created-conflict-record:field-conflict-ind-call" ],
            "value" : [ "node" ]
          }
        },
        { "data_set" : {
            "data" : [ "created-conflict-record:field-conflict-group" ],
            "value" : [ "term" ]
          }
        }
      ]
    }
  }');
  $items['rules_detect_individual_hard_conflicts'] = entity_import('rules_config', '{ "rules_detect_individual_hard_conflicts" : {
      "LABEL" : "Detect individual hard conflicts",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "flag", "php" ],
      "USES VARIABLES" : {
        "current_conflict_list_item_individual" : { "label" : "Current conflict list item individual", "type" : "user" },
        "saved_node_individual_item" : { "label" : "Saved node individual list item", "type" : "user" },
        "saved_node" : { "label" : "Saved node", "type" : "node" },
        "current_conflicts_list_item" : { "label" : "Current conflict node", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "current-conflict-list-item-individual" ],
            "value" : [ "saved-node-individual-item" ]
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "conflict",
              "param_title" : "[current-conflict-list-item-individual:name] is called to both [saved-node:title] and [current-conflicts-list-item:title] ",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "conflict_entity_created" : "Created conflict entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "conflict-entity-created:field-conflict-grp-call" ],
            "value" : [ "current-conflicts-list-item" ]
          }
        },
        { "data_set" : {
            "data" : [ "conflict-entity-created:field-conflict-ind-call" ],
            "value" : [ "saved-node" ]
          }
        },
        { "data_set" : {
            "data" : [ "conflict-entity-created:field-conflict-usr" ],
            "value" : [ "saved-node-individual-item" ]
          }
        },
        { "entity_save" : { "data" : [ "conflict-entity-created" ], "immediate" : 1 } },
        { "flag_flagnode" : {
            "flag" : "hard_conflict",
            "node" : [ "conflict-entity-created" ],
            "flagging_user" : "1",
            "permission_check" : 1
          }
        },
        { "drupal_message" : {
            "message" : "\\u003Cstrong\\u003ECONFLICT:\\u003C\\/strong\\u003E \\u003C?php \\r\\nif(isset($conflict_entity_created-\\u003Efield_conflict_usr[\\u0027und\\u0027])) { \\r\\n  $conflict_object = user_load($conflict_entity_created-\\u003Efield_conflict_usr[\\u0027und\\u0027][\\u00270\\u0027][\\u0027target_id\\u0027]);\\r\\n  $conflict_fname_dirty = field_get_items(\\u0027user\\u0027, $conflict_object, \\u0027field_user_fname\\u0027);\\r\\n  $conflict_lname_dirty = field_get_items(\\u0027user\\u0027, $conflict_object, \\u0027field_user_lname\\u0027);\\r\\n  $conflict_fname = field_view_value(\\u0027user\\u0027, $conflict_object, \\u0027field_user_fname\\u0027, $conflict_fname_dirty[0]);\\r\\n  $conflict_lname = field_view_value(\\u0027user\\u0027, $conflict_object, \\u0027field_user_lname\\u0027, $conflict_lname_dirty[0]);\\r\\n  $conflict_name = $conflict_fname[\\u0027#markup\\u0027] . \\u0027 \\u0027 . $conflict_lname[\\u0027#markup\\u0027];\\r\\n  $conflict_path = entity_uri(\\u0027user\\u0027, $conflict_object);\\r\\n  $conflict_object_link = l($conflict_name, $conflict_path[\\u0027path\\u0027]);\\r\\n} \\r\\nelseif(isset($conflict_entity_created-\\u003Efield_conflict_group[\\u0027und\\u0027])) {\\r\\n  $conflict_object = taxonomy_term_load($conflict_entity_created-\\u003Efield_conflict_group[\\u0027und\\u0027][\\u00270\\u0027][\\u0027tid\\u0027]);\\r\\n  $conflict_name = $conflict_object-\\u003Ename;\\r\\n  $conflict_path = entity_uri(\\u0027taxonomy_term\\u0027, $conflict_object);\\r\\n  $conflict_object_link = l($conflict_name, $conflict_path[\\u0027path\\u0027]);\\r\\n} \\r\\nprint $conflict_object_link;\\r\\n?\\u003E is scheduled for \\u003Ca href=\\u0022[conflict-entity-created:field-conflict-grp-call:url]\\u0022\\u003E[conflict-entity-created:field-conflict-grp-call:title]\\u003C\\/a\\u003E and \\u003Ca href=\\u0022[conflict-entity-created:field-conflict-ind-call:url]\\u0022\\u003E[conflict-entity-created:field-conflict-ind-call:title]\\u003C\\/a\\u003E at the same time. \\u003Cspan class=\\u0022conflict-msg-buttons\\u0022\\u003E\\u003C?php print flag_create_link(\\u0027conflict_approved\\u0027, $conflict_entity_created-\\u003Enid); ?\\u003E \\u003C?php print flag_create_link(\\u0027conflict_postponed\\u0027, $conflict_entity_created-\\u003Enid); ?\\u003E\\u003C\\/span\\u003E\\r\\n\\r\\n",
            "type" : "error",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  $items['rules_detect_individual_soft_conflicts'] = entity_import('rules_config', '{ "rules_detect_individual_soft_conflicts" : {
      "LABEL" : "Detect individual soft conflicts with groups",
      "PLUGIN" : "rule",
      "TAGS" : [ "conflict detection" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user_term" : { "label" : "user term", "type" : "taxonomy_term" },
        "conflict_terms" : { "label" : "conflict terms", "type" : "list\\u003Ctaxonomy_term\\u003E" },
        "conflict_node" : { "label" : "conflict_node", "type" : "node" },
        "saved_node" : { "label" : "saved_node", "type" : "node" },
        "conflict_user" : { "label" : "conflict_user", "type" : "user" }
      },
      "IF" : [
        { "list_contains" : { "list" : [ "conflict-terms" ], "item" : [ "user-term" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "conflict",
              "param_title" : "[conflict-user:name] is called to both [conflict-node:title] and [saved-node:title]",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "created_conflict_record" : "created_conflict_record" } }
          }
        },
        { "data_set" : {
            "data" : [ "created-conflict-record:field-conflict-grp-call" ],
            "value" : [ "conflict-node" ]
          }
        },
        { "data_set" : {
            "data" : [ "created-conflict-record:field-conflict-ind-call" ],
            "value" : [ "saved-node" ]
          }
        },
        { "data_set" : {
            "data" : [ "created-conflict-record:field-conflict-usr" ],
            "value" : [ "conflict-user" ]
          }
        }
      ]
    }
  }');
  $items['rules_detect_resource_conflict_soft_errors'] = entity_import('rules_config', '{ "rules_detect_resource_conflict_soft_errors" : {
      "LABEL" : "detect resource conflict soft errors",
      "PLUGIN" : "rule set",
      "TAGS" : [ "conflict detection" ],
      "REQUIRES" : [ "rules", "resource_conflict" ],
      "USES VARIABLES" : {
        "saved_node" : { "label" : "saved_node", "type" : "node" },
        "conflict_node" : { "label" : "conflict-node", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "variable_added" : { "error_messages" : "Error Messages" } },
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "list\\u003Ctext\\u003E", "value" : [ "" ] },
                  "PROVIDE" : { "variable_added" : { "error_messages" : "Error Messages" } }
                }
              }
            ],
            "LABEL" : "Set error message list"
          }
        },
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "saved-node" ], "type" : { "value" : { "call" : "call" } } } },
              { "node_is_of_type" : {
                  "node" : [ "conflict-node" ],
                  "type" : { "value" : { "call" : "call" } }
                }
              },
              { "NOT data_is" : {
                  "data" : [ "saved-node:field-event-groups-tax" ],
                  "value" : [ "conflict-node:field-event-groups-tax" ]
                }
              }
            ],
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "saved-node:field-event-groups-tax" ] },
                  "ITEM" : { "current_term" : "Current term" },
                  "DO" : [
                    { "LOOP" : {
                        "USING" : { "list" : [ "current-term:parents-all" ] },
                        "ITEM" : { "term_parent" : "Current term parent" },
                        "DO" : [
                          { "component_rules_detect_group_parent_soft_conflicts" : {
                              "parent_term" : [ "term-parent" ],
                              "term_list" : [ "conflict-node:field-event-groups-tax" ],
                              "conflict_node" : [ "conflict_node" ],
                              "term" : [ "current-term" ],
                              "node" : [ "saved-node" ]
                            }
                          }
                        ]
                      }
                    }
                  ]
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "conflict-node:field-event-groups-tax" ] },
                  "ITEM" : { "current_conflict_term" : "Current conflict node term" },
                  "DO" : [
                    { "LOOP" : {
                        "USING" : { "list" : [ "current-conflict-term:parents-all" ] },
                        "ITEM" : { "current_conflict_term_parent" : "current conflict term parent" },
                        "DO" : [
                          { "component_rules_detect_group_parent_soft_conflicts" : {
                              "parent_term" : [ "current-conflict-term-parent" ],
                              "term_list" : [ "saved-node:field-event-groups-tax" ],
                              "conflict_node" : [ "saved-node" ],
                              "term" : [ "current-conflict-term" ],
                              "node" : [ "conflict-node" ]
                            }
                          }
                        ]
                      }
                    }
                  ]
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "saved-node:field-event-individuals" ] },
                  "ITEM" : { "current_individual" : "Current individual" },
                  "DO" : [
                    { "LOOP" : {
                        "USING" : { "list" : [ "current-individual:field-user-groups" ] },
                        "ITEM" : { "current_individual_group" : "Current individual group" },
                        "DO" : [
                          { "component_rules_detect_individual_soft_conflicts" : {
                              "user_term" : [ "current-individual-group" ],
                              "conflict_terms" : [ "conflict-node:field-event-groups-tax" ],
                              "conflict_node" : [ "conflict_node" ],
                              "saved_node" : [ "saved_node" ],
                              "conflict_user" : [ "current-individual" ]
                            }
                          }
                        ]
                      }
                    }
                  ]
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "conflict-node:field-event-individuals" ] },
                  "ITEM" : { "current_conflict_individual" : "Current conflict individual" },
                  "DO" : [
                    { "LOOP" : {
                        "USING" : { "list" : [ "current-conflict-individual:field-user-groups" ] },
                        "ITEM" : { "current_conflict_individual_group" : "Current conflict individual group" },
                        "DO" : [
                          { "component_rules_detect_individual_soft_conflicts" : {
                              "user_term" : [ "current-conflict-individual-group" ],
                              "conflict_terms" : [ "saved-node:field-event-groups-tax" ],
                              "conflict_node" : [ "saved-node" ],
                              "saved_node" : [ "conflict-node" ],
                              "conflict_user" : [ "current-conflict-individual" ]
                            }
                          }
                        ]
                      }
                    }
                  ]
                }
              }
            ],
            "LABEL" : "Check for soft conflicts"
          }
        },
        { "RULE" : {
            "IF" : [ { "NOT data_is_empty" : { "data" : [ "error-messages" ] } } ],
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "error-messages" ] },
                  "ITEM" : { "list_item" : "Current list item" },
                  "DO" : [ { "resource_conflict_form_error" : { "message" : [ "list-item" ] } } ]
                }
              }
            ],
            "LABEL" : "set form validation errors"
          }
        }
      ]
    }
  }');
  $items['rules_detect_resource_hard_errors'] = entity_import('rules_config', '{ "rules_detect_resource_hard_errors" : {
      "LABEL" : "Detect resource hard errors",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules", "resource_conflict" ],
      "USES VARIABLES" : {
        "saved_node" : { "label" : "Saved node", "type" : "node" },
        "current_conflicts_list_item" : { "label" : "Current conflicted node", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "variable_added" : { "error_messages" : "Error Messages" } },
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "list\\u003Ctext\\u003E" },
                  "PROVIDE" : { "variable_added" : { "error_messages" : "Error Messages" } }
                }
              }
            ],
            "LABEL" : "Set error message list"
          }
        },
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "saved-node" ], "type" : { "value" : { "call" : "call" } } } },
              { "node_is_of_type" : {
                  "node" : [ "current-conflicts-list-item" ],
                  "type" : { "value" : { "call" : "call" } }
                }
              },
              { "AND" : [
                  { "OR" : [
                      { "AND" : [
                          { "NOT data_is_empty" : { "data" : [ "saved-node:field-event-groups-tax" ] } },
                          { "data_is" : {
                              "data" : [ "saved-node:field-event-groups-tax" ],
                              "value" : [ "current-conflicts-list-item:field-event-groups-tax" ]
                            }
                          }
                        ]
                      },
                      { "AND" : [
                          { "NOT data_is_empty" : { "data" : [ "saved-node:field-event-individuals" ] } },
                          { "data_is" : {
                              "data" : [ "saved-node:field-event-individuals" ],
                              "value" : [ "current-conflicts-list-item:field-event-individuals" ]
                            }
                          }
                        ]
                      }
                    ]
                  }
                ]
              }
            ],
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "current-conflicts-list-item:field-event-groups-tax" ] },
                  "ITEM" : { "current_conflict_list_item_group" : "Current conflict list item group" },
                  "DO" : [
                    { "LOOP" : {
                        "USING" : { "list" : [ "saved-node:field-event-groups-tax" ] },
                        "ITEM" : { "saved_node_group_item" : "Saved node group list item" },
                        "DO" : [
                          { "component_rules_detect_group_hard_conflicts" : {
                              "current_conflict_list_item_group" : [ "saved-node-group-item" ],
                              "saved_node_group_item" : [ "saved_node_group_item" ],
                              "saved_node" : [ "saved_node" ],
                              "current_conflicts_list_item" : [ "current_conflicts_list_item" ]
                            }
                          }
                        ]
                      }
                    }
                  ]
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "current-conflicts-list-item:field-event-individuals" ] },
                  "ITEM" : { "current_conflict_list_item_individual" : "Current conflict list item individual" },
                  "DO" : [
                    { "LOOP" : {
                        "USING" : { "list" : [ "saved-node:field-event-individuals" ] },
                        "ITEM" : { "saved_node_individual_item" : "Saved node individual list item" },
                        "DO" : [
                          { "component_rules_detect_individual_hard_conflicts" : {
                              "current_conflict_list_item_individual" : [ "current_conflict_list_item_individual" ],
                              "saved_node_individual_item" : [ "saved_node_individual_item" ],
                              "saved_node" : [ "saved_node" ],
                              "current_conflicts_list_item" : [ "current_conflicts_list_item" ]
                            }
                          }
                        ]
                      }
                    }
                  ]
                }
              }
            ],
            "LABEL" : "Check for hard conflicts"
          }
        },
        { "RULE" : {
            "IF" : [ { "NOT data_is_empty" : { "data" : [ "error-messages" ] } } ],
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "error-messages" ] },
                  "ITEM" : { "list_item" : "Current list item" },
                  "DO" : [ { "resource_conflict_form_error" : { "message" : [ "list-item" ] } } ]
                }
              }
            ],
            "LABEL" : "set form validation errors"
          }
        }
      ]
    }
  }');
  $items['rules_display_hard_conflict_message'] = entity_import('rules_config', '{ "rules_display_hard_conflict_message" : {
      "LABEL" : "Display hard conflict message",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "flag", "php" ],
      "USES VARIABLES" : { "conflict_node" : { "label" : "Conflict node", "type" : "node" } },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "conflict-node" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "conflict-node" ],
            "type" : { "value" : { "conflict" : "conflict" } }
          }
        },
        { "node_is_of_type" : {
            "node" : [ "conflict-node:field-conflict-grp-call" ],
            "type" : { "value" : { "call" : "call" } }
          }
        },
        { "node_is_of_type" : {
            "node" : [ "conflict-node:field-conflict-ind-call" ],
            "type" : { "value" : { "call" : "call" } }
          }
        },
        { "NOT flag_flagged_node" : {
            "flag" : "conflict_approved",
            "node" : [ "conflict-node" ],
            "flagging_user" : "1"
          }
        },
        { "NOT flag_flagged_node" : {
            "flag" : "conflict_postponed",
            "node" : [ "conflict-node" ],
            "flagging_user" : "1"
          }
        },
        { "flag_flagged_node" : {
            "flag" : "hard_conflict",
            "node" : [ "conflict-node" ],
            "flagging_user" : "1"
          }
        }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "\\u003Cstrong\\u003ECONFLICT:\\u003C\\/strong\\u003E \\u003C?php \\r\\nif(isset($conflict_node-\\u003Efield_conflict_usr[\\u0027und\\u0027])) { \\r\\n  $conflict_object = user_load($conflict_node-\\u003Efield_conflict_usr[\\u0027und\\u0027][\\u00270\\u0027][\\u0027target_id\\u0027]);\\r\\n  $conflict_fname_dirty = field_get_items(\\u0027user\\u0027, $conflict_object, \\u0027field_user_fname\\u0027);\\r\\n  $conflict_lname_dirty = field_get_items(\\u0027user\\u0027, $conflict_object, \\u0027field_user_lname\\u0027);\\r\\n  $conflict_fname = field_view_value(\\u0027user\\u0027, $conflict_object, \\u0027field_user_fname\\u0027, $conflict_fname_dirty[0]);\\r\\n  $conflict_lname = field_view_value(\\u0027user\\u0027, $conflict_object, \\u0027field_user_lname\\u0027, $conflict_lname_dirty[0]);\\r\\n  $conflict_name = $conflict_fname[\\u0027#markup\\u0027] . \\u0027 \\u0027 . $conflict_lname[\\u0027#markup\\u0027];\\r\\n  $conflict_path = entity_uri(\\u0027user\\u0027, $conflict_object);\\r\\n  $conflict_object_link = l($conflict_name, $conflict_path[\\u0027path\\u0027]);\\r\\n} \\r\\nelseif(isset($conflict_node-\\u003Efield_conflict_group[\\u0027und\\u0027])) {\\r\\n  $conflict_object = taxonomy_term_load($conflict_node-\\u003Efield_conflict_group[\\u0027und\\u0027][\\u00270\\u0027][\\u0027tid\\u0027]);\\r\\n  $conflict_name = $conflict_object-\\u003Ename;\\r\\n  $conflict_path = entity_uri(\\u0027taxonomy_term\\u0027, $conflict_object);\\r\\n  $conflict_object_link = l($conflict_name, $conflict_path[\\u0027path\\u0027]);\\r\\n} \\r\\nprint $conflict_object_link;\\r\\n?\\u003E is scheduled for \\u003Ca href=\\u0022[conflict-node:field-conflict-grp-call:url]\\u0022\\u003E[conflict-node:field-conflict-grp-call:title]\\u003C\\/a\\u003E and \\u003Ca href=\\u0022[conflict-node:field-conflict-ind-call:url]\\u0022\\u003E[conflict-node:field-conflict-ind-call:title]\\u003C\\/a\\u003E at the same time. \\u003Cspan class=\\u0022conflict-msg-buttons\\u0022\\u003E\\u003C?php print flag_create_link(\\u0027conflict_approved\\u0027, $conflict_node-\\u003Enid); ?\\u003E \\u003C?php print flag_create_link(\\u0027conflict_postponed\\u0027, $conflict_node-\\u003Enid); ?\\u003E\\u003C\\/span\\u003E\\r\\n",
            "type" : "error",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  $items['rules_display_unapproved_conflict_message'] = entity_import('rules_config', '{ "rules_display_unapproved_conflict_message" : {
      "LABEL" : "Display unapproved conflict message",
      "PLUGIN" : "rule",
      "ACTIVE" : false,
      "TAGS" : [ "conflict display" ],
      "REQUIRES" : [ "rules", "flag", "php" ],
      "USES VARIABLES" : { "conflict_node" : { "label" : "conflict node", "type" : "node" } },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "conflict-node" ], "type" : "node" } },
        { "NOT flag_flagged_node" : {
            "flag" : "hard_conflict",
            "node" : [ "conflict-node" ],
            "flagging_user" : "1"
          }
        },
        { "node_is_of_type" : {
            "node" : [ "conflict-node" ],
            "type" : { "value" : { "conflict" : "conflict" } }
          }
        },
        { "node_is_of_type" : {
            "node" : [ "conflict-node:field-conflict-grp-call" ],
            "type" : { "value" : { "call" : "call" } }
          }
        },
        { "node_is_of_type" : {
            "node" : [ "conflict-node:field-conflict-ind-call" ],
            "type" : { "value" : { "call" : "call" } }
          }
        },
        { "NOT flag_flagged_node" : {
            "flag" : "conflict_approved",
            "node" : [ "conflict-node" ],
            "flagging_user" : "1"
          }
        },
        { "NOT flag_flagged_node" : {
            "flag" : "conflict_postponed",
            "node" : [ "conflict-node" ],
            "flagging_user" : "1"
          }
        }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "\\u003Cstrong\\u003ECONFLICT:\\u003C\\/strong\\u003E \\u003C?php \\r\\nif(isset($conflict_node-\\u003Efield_conflict_usr[\\u0027und\\u0027])) { \\r\\n  $conflict_object = user_load($conflict_node-\\u003Efield_conflict_usr[\\u0027und\\u0027][\\u00270\\u0027][\\u0027target_id\\u0027]);\\r\\n  $conflict_fname_dirty = field_get_items(\\u0027user\\u0027, $conflict_object, \\u0027field_user_fname\\u0027);\\r\\n  $conflict_lname_dirty = field_get_items(\\u0027user\\u0027, $conflict_object, \\u0027field_user_lname\\u0027);\\r\\n  $conflict_fname = field_view_value(\\u0027user\\u0027, $conflict_object, \\u0027field_user_fname\\u0027, $conflict_fname_dirty[0]);\\r\\n  $conflict_lname = field_view_value(\\u0027user\\u0027, $conflict_object, \\u0027field_user_lname\\u0027, $conflict_lname_dirty[0]);\\r\\n  $conflict_name = $conflict_fname[\\u0027#markup\\u0027] . \\u0027 \\u0027 . $conflict_lname[\\u0027#markup\\u0027];\\r\\n  $conflict_path = entity_uri(\\u0027user\\u0027, $conflict_object);\\r\\n  $conflict_object_link = l($conflict_name, $conflict_path[\\u0027path\\u0027]);\\r\\n} \\r\\nelseif(isset($conflict_node-\\u003Efield_conflict_group[\\u0027und\\u0027])) {\\r\\n  $conflict_object = taxonomy_term_load($conflict_node-\\u003Efield_conflict_group[\\u0027und\\u0027][\\u00270\\u0027][\\u0027tid\\u0027]);\\r\\n  $conflict_name = $conflict_object-\\u003Ename;\\r\\n  $conflict_path = entity_uri(\\u0027taxonomy_term\\u0027, $conflict_object);\\r\\n  $conflict_object_link = l($conflict_name, $conflict_path[\\u0027path\\u0027]);\\r\\n} \\r\\nprint $conflict_object_link;\\r\\n?\\u003E is scheduled for \\u003Ca href=\\u0022[conflict-node:field-conflict-grp-call:url]\\u0022\\u003E[conflict-node:field-conflict-grp-call:title]\\u003C\\/a\\u003E and \\u003Ca href=\\u0022[conflict-node:field-conflict-ind-call:url]\\u0022\\u003E[conflict-node:field-conflict-ind-call:title]\\u003C\\/a\\u003E at the same time. \\u003Cspan class=\\u0022conflict-msg-buttons\\u0022\\u003E\\u003C?php print flag_create_link(\\u0027conflict_approved\\u0027, $conflict_node-\\u003Enid); ?\\u003E \\u003C?php print flag_create_link(\\u0027conflict_postponed\\u0027, $conflict_node-\\u003Enid); ?\\u003E\\u003C\\/span\\u003E\\r\\n",
            "type" : "warning",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  $items['rules_display_unapproved_conflict_messages'] = entity_import('rules_config', '{ "rules_display_unapproved_conflict_messages" : {
      "LABEL" : "Load unapproved conflicts",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "conflict display" ],
      "REQUIRES" : [ "views_bulk_operations", "rules", "rb_views" ],
      "ON" : [ "rb_views_event_view_complete" ],
      "IF" : [
        { "views_bulk_operations_condition_result_count" : { "view" : "pending_conflicts|page_1", "minimum" : "1" } }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "pending_conflicts|page_1" },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-list" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_display_unapproved_conflict_message" : { "conflict_node" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_display_unapproved_hard_conflict_message'] = entity_import('rules_config', '{ "rules_display_unapproved_hard_conflict_message" : {
      "LABEL" : "Display unapproved hard conflict message",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "views_bulk_operations", "rules", "rb_views" ],
      "ON" : [ "rb_views_event_view_complete" ],
      "IF" : [
        { "views_bulk_operations_condition_result_count" : { "view" : "pending_conflicts|page_2", "minimum" : "1" } }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "pending_conflicts|page_2" },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-list" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_display_hard_conflict_message" : { "conflict_node" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_group_hard_conflicts'] = entity_import('rules_config', '{ "rules_group_hard_conflicts" : {
      "LABEL" : "Detect group hard conflicts",
      "PLUGIN" : "rule",
      "TAGS" : [ "conflict detection" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "term" : { "label" : "term", "type" : "taxonomy_term" },
        "term_list" : { "label" : "term_list", "type" : "list\\u003Ctaxonomy_term\\u003E" },
        "conflict_node" : { "label" : "conflict_node", "type" : "node" },
        "error_messages" : { "label" : "error_messages", "type" : "list\\u003Ctext\\u003E" }
      },
      "IF" : [
        { "list_contains" : { "list" : [ "term-list" ], "item" : [ "term" ] } }
      ],
      "DO" : [
        { "list_add" : {
            "list" : [ "error-messages" ],
            "item" : "\\u003Ca href=\\u0022[term:url]\\u0022\\u003E[term:name]\\u003C\\/a\\u003E is already called to \\u003Ca href=\\u0022[conflict-node:url]\\u0022\\u003E[conflict-node:title]\\u003C\\/a\\u003E at this time.",
            "unique" : 1
          }
        }
      ]
    }
  }');
  $items['rules_hard_resource_conflicts'] = entity_import('rules_config', '{ "rules_hard_resource_conflicts" : {
      "LABEL" : "Hard resource conflicts",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "resource_conflict", "rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [ { "resource_conflict_contains_conflict" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "resource_conflict_load_conflict_list" : {
            "USING" : { "node" : [ "node" ] },
            "PROVIDE" : { "conflict_list" : { "conflict_list" : "Conflict List" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "conflict-list" ] },
            "ITEM" : { "current_conflict_list_item" : "Current conflict list item" },
            "DO" : [
              { "component_rules_detect_resource_hard_errors" : {
                  "saved_node" : [ "node" ],
                  "current_conflicts_list_item" : [ "current-conflict-list-item" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_individual_hard_conflict'] = entity_import('rules_config', '{ "rules_individual_hard_conflict" : {
      "LABEL" : "Detect Individual hard conflicts",
      "PLUGIN" : "rule",
      "TAGS" : [ "conflict detection" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user" : { "label" : "user", "type" : "user" },
        "user_list" : { "label" : "user_list", "type" : "list\\u003Cuser\\u003E" },
        "conflict_node" : { "label" : "conflict_node", "type" : "node" },
        "error_messages" : { "label" : "error_messages", "type" : "list\\u003Ctext\\u003E" }
      },
      "IF" : [
        { "list_contains" : { "list" : [ "user-list" ], "item" : [ "user" ] } }
      ],
      "DO" : [
        { "list_add" : {
            "list" : [ "error-messages" ],
            "item" : "\\u003Ca href=\\u0022[user:url]\\u0022\\u003E[user:field_user_fname] [user:field_user_lname]\\u003C\\/a\\u003E is already called to \\u003Ca href=\\u0022[conflict-node:url]\\u0022\\u003E[conflict-node:title]\\u003C\\/a\\u003E at this time.",
            "unique" : 1
          }
        }
      ]
    }
  }');
  $items['rules_postpone_a_conflict'] = entity_import('rules_config', '{ "rules_postpone_a_conflict" : {
      "LABEL" : "postpone a conflict",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "conflicts" ],
      "REQUIRES" : [ "rules", "rules_scheduler", "flag" ],
      "ON" : [ "flag_flagged_conflict_postponed" ],
      "DO" : [
        { "schedule" : {
            "component" : "rules_unpostpone_conflict",
            "date" : "+2 hours",
            "param_conflict_node" : [ "flagged-node" ]
          }
        }
      ]
    }
  }');
  $items['rules_production_is_created'] = entity_import('rules_config', '{ "rules_production_is_created" : {
      "LABEL" : "production is created",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Master Calendar" ],
      "REQUIRES" : [ "rules", "taxonomy_copy" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "production" : "production" } }
          }
        }
      ],
      "DO" : [
        { "taxonomy_copy_copy_term" : {
            "USING" : {
              "oldtid" : [ "node:field-group-structure" ],
              "newvid" : "group",
              "newparent" : [ "node:field-season" ],
              "newname" : [ "node:title" ]
            },
            "PROVIDE" : { "created_term" : { "created_term" : "Created term" } }
          }
        },
        { "data_set" : { "data" : [ "node:field-prod-tid" ], "value" : [ "created-term:tid" ] } }
      ]
    }
  }');
  $items['rules_production_is_deleted'] = entity_import('rules_config', '{ "rules_production_is_deleted" : {
      "LABEL" : "production is deleted",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_delete" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "production" : "production" } }
          }
        },
        { "NOT data_is_empty" : { "data" : [ "node:field-prod-tid" ] } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "taxonomy_term", "id" : [ "node:field-prod-tid" ] },
            "PROVIDE" : { "entity_fetched" : { "fetched_term" : "Fetched term" } }
          }
        },
        { "entity_delete" : { "data" : [ "fetched-term" ] } }
      ]
    }
  }');
  $items['rules_promote_to_company_administrator'] = entity_import('rules_config', '{ "rules_promote_to_company_administrator" : {
      "LABEL" : "Promote to company administrator",
      "PLUGIN" : "action set",
      "TAGS" : [ "VBO actions" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "user", "type" : "user" } },
      "ACTION SET" : [
        { "user_add_role" : { "account" : [ "user" ], "roles" : { "value" : { "4" : "4" } } } }
      ]
    }
  }');
  $items['rules_resource_conflict_hard_errors'] = entity_import('rules_config', '{ "rules_resource_conflict_hard_errors" : {
      "LABEL" : "detect resource conflict hard errors",
      "PLUGIN" : "rule set",
      "TAGS" : [ "conflict detection" ],
      "REQUIRES" : [ "rules", "resource_conflict" ],
      "USES VARIABLES" : {
        "saved_node" : { "label" : "node", "type" : "node" },
        "conflict_node" : { "label" : "conflict-node", "type" : "node" },
        "form" : { "label" : "form", "type" : "form" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "variable_added" : { "error_messages" : "Error Messages" } },
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "list\\u003Ctext\\u003E", "value" : [ "" ] },
                  "PROVIDE" : { "variable_added" : { "error_messages" : "Error Messages" } }
                }
              }
            ],
            "LABEL" : "Set error message list"
          }
        },
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "saved-node" ], "type" : { "value" : { "call" : "call" } } } },
              { "node_is_of_type" : {
                  "node" : [ "conflict-node" ],
                  "type" : { "value" : { "call" : "call" } }
                }
              }
            ],
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "saved-node:field-event-individuals" ] },
                  "ITEM" : { "current_individual" : "Current individual" },
                  "DO" : [
                    { "component_rules_individual_hard_conflict" : {
                        "user" : [ "current-individual" ],
                        "user_list" : [ "conflict-node:field-event-individuals" ],
                        "conflict_node" : [ "conflict_node" ],
                        "error_messages" : [ "error_messages" ]
                      }
                    }
                  ]
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "saved-node:field-event-groups-tax" ] },
                  "ITEM" : { "current_term" : "Current term" },
                  "DO" : [
                    { "component_rules_group_hard_conflicts" : {
                        "term" : [ "current-term" ],
                        "term_list" : [ "conflict-node:field-event-groups-tax" ],
                        "conflict_node" : [ "conflict_node" ],
                        "error_messages" : [ "error_messages" ]
                      }
                    }
                  ]
                }
              }
            ],
            "LABEL" : "Check for hard conflicts"
          }
        },
        { "RULE" : {
            "IF" : [ { "NOT data_is_empty" : { "data" : [ "error-messages" ] } } ],
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "error-messages" ] },
                  "ITEM" : { "list_item" : "Current list item" },
                  "DO" : [ { "resource_conflict_form_error" : { "message" : [ "list-item" ] } } ]
                }
              }
            ],
            "LABEL" : "set form validation errors"
          }
        }
      ]
    }
  }');
  $items['rules_send_schedule_email_to_group_members_'] = entity_import('rules_config', '{ "rules_send_schedule_email_to_group_members_" : {
      "LABEL" : "Send schedule email to group members ",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "current_term" : { "label" : "Current Term", "type" : "taxonomy_term" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_type" : { "entity" : [ "current-term" ], "type" : "taxonomy_term" } }
            ],
            "DO" : [],
            "LABEL" : "List users in term"
          }
        }
      ]
    }
  }');
  $items['rules_soft_resource_conflicts'] = entity_import('rules_config', '{ "rules_soft_resource_conflicts" : {
      "LABEL" : "soft resource conflicts",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "TAGS" : [ "conflict detection" ],
      "REQUIRES" : [ "resource_conflict", "rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [ { "resource_conflict_contains_conflict" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "resource_conflict_load_conflict_list" : {
            "USING" : { "node" : [ "node" ] },
            "PROVIDE" : { "conflict_list" : { "conflict_list" : "Conflict List" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "conflict-list" ] },
            "ITEM" : { "current_conflict_node" : "Current conflict node" },
            "DO" : [
              { "component_rules_detect_resource_conflict_soft_errors" : {
                  "saved_node" : [ "node" ],
                  "conflict_node" : [ "current-conflict-node" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_unblock_a_user'] = entity_import('rules_config', '{ "rules_unblock_a_user" : {
      "LABEL" : "Unblock a user",
      "PLUGIN" : "action set",
      "TAGS" : [ "VBO actions" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "user", "type" : "user" } },
      "ACTION SET" : [ { "user_unblock" : { "account" : [ "user" ] } } ]
    }
  }');
  $items['rules_unpostpone_conflict'] = entity_import('rules_config', '{ "rules_unpostpone_conflict" : {
      "LABEL" : "Unpostpone conflict",
      "PLUGIN" : "rule",
      "TAGS" : [ "conflicts" ],
      "REQUIRES" : [ "rules", "flag" ],
      "USES VARIABLES" : { "conflict_node" : { "label" : "conflict_node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "conflict-node" ],
            "type" : { "value" : { "conflict" : "conflict" } }
          }
        },
        { "flag_flagged_node" : {
            "flag" : "conflict_postponed",
            "node" : [ "conflict-node" ],
            "flagging_user" : "1"
          }
        }
      ],
      "DO" : [
        { "flag_unflagnode" : {
            "flag" : "conflict_postponed",
            "node" : [ "conflict-node" ],
            "flagging_user" : "1",
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_update_master_event_color_on_prod_update_'] = entity_import('rules_config', '{ "rules_update_master_event_color_on_prod_update_" : {
      "LABEL" : "update master event color on prod update ",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "views_bulk_operations" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "production" : "production" } }
          }
        },
        { "views_bulk_operations_condition_result_count" : {
            "view" : "production_events|default",
            "args" : [ "node:nid" ],
            "minimum" : "1"
          }
        }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "production_events|default", "args" : [ "node:nid" ] },
            "PROVIDE" : { "entity_list" : { "events" : "master calendar events" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "events" ] },
            "ITEM" : { "event" : "Current event" },
            "DO" : [
              { "component_rules_update_mc_event_color" : { "production" : [ "node" ], "event" : [ "event" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_update_mc_event_color'] = entity_import('rules_config', '{ "rules_update_mc_event_color" : {
      "LABEL" : "Update MC event color",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "production" : { "label" : "Production", "type" : "node" },
        "event" : { "label" : "MC Event", "type" : "node" }
      },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "production" ],
            "type" : { "value" : { "production" : "production" } }
          }
        },
        { "node_is_of_type" : {
            "node" : [ "event" ],
            "type" : { "value" : { "master_calendar_event" : "master_calendar_event" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "event:field-prod-color" ],
            "value" : [ "production:field-prod-color" ]
          }
        }
      ]
    }
  }');
  return $items;
}
