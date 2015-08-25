<?php

function spkaderfunctiesafdeling_views_beeindig($relationship_type_id, $relationship_id) {
  $relationship_types = variable_get('spkaderfunctiesafdeling_end_relationship_types');
  if (!is_array($relationship_types)) {
    $relationship_types = array();
  }

  $return = '';
  if (!empty($relationship_types[$relationship_type_id]) && spkaderfunctiesafdeling_check_relationship($relationship_id)) {
    return 'Beëindig';
  }
  return $return;
}

function spkaderfunctiesafdeling_check_new() {
  civicrm_initialize();
  $relationship_types = variable_get('spkaderfunctiesafdeling_new_relationship_types', array());
  if (empty($relationship_types)) {
    return false;
  }
  $afdelings_contacten = spkaderfunctiesafdeling_get_afdelingscontacten();
  if (empty($afdelings_contacten)) {
    return false;
  }
  $individuals = spkaderfunctiesafdeling_get_individuals();
  if (empty($individuals)) {
    return false;
  }
  return true;
}

function spkaderfunctiesafdeling_check_autocomplete() {
  civicrm_initialize();
  $individuals = spkaderfunctiesafdeling_get_individuals();
  if (empty($individuals)) {
    return false;
  }
  return true;
}