<?php

// If the term is reserved, we do not print it.
print schedulearts_undeletables_reserved_term_access($variables['view']->result[$variables['view']->row_index]->tid) ? $variables['output'] : '';
