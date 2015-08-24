<?php

function spkaderfunctiesafdeling_get_civicrm_relationship_types() {
  civicrm_initialize();
  $dao = CRM_Core_DAO::executeQuery("SELECT * FROM `civicrm_relationship_type` WHERE is_active = 1");
  $relationship_types = array();
  while($dao->fetch()) {
    $relationship_types[$dao->id] = $dao->label_a_b;
  }
  return $relationship_types;
}

/**
 * Check wether the user has access to see both contacts of a relationship
 *
 * @param $relationship_id
 */
function spkaderfunctiesafdeling_check_relationship($relationship_id) {
  civicrm_initialize();
  try {
    $relationship = civicrm_api3('Relationship', 'getsingle', array('id' => $relationship_id));

    if (CRM_Contact_BAO_Contact_Permission::allow($relationship['contact_id_a']) && CRM_Contact_BAO_Contact_Permission::allow($relationship['contact_id_b'])) {
      return true;
    }

  } catch (Exception $e) {
    //do nothing
  }
  return false;
}

function spkaderfunctiesafdeling_get_afdelingscontacten() {
  civicrm_initialize();
  $session = CRM_Core_Session::singleton();
  $config = SpKaderfunctiesAfdelingConfigCiviCRM::getInstance();

  $sql = "SELECT civicrm_contact.*
          FROM `civicrm_relationship` INNER JOIN civicrm_contact ON civicrm_contact.id = civicrm_relationship.contact_id_b
          WHERE `contact_id_a` = %1
          AND relationship_type_id IN (".implode(',', $config->getVoorzitterRelationshipTypes()).")
          AND is_active = 1
          AND (start_date <= NOW() or start_date IS NULL)
          AND (end_date >= NOW() OR end_date IS NULL)
          ORDER BY civicrm_contact.sort_name";
  $params[1] = array($session->getLoggedInContactID(), 'Integer');

  $dao = CRM_Core_DAO::executeQuery($sql, $params);
  $return = array();
  while($dao->fetch()) {
    if (CRM_Contact_BAO_Contact_Permission::allow($dao->id)) {
      $return[$dao->id] = $dao->display_name;
    }
  }
  return $return;
}

function spkaderfunctiesafdeling_get_individuals() {
  civicrm_initialize();
  $session = CRM_Core_Session::singleton();
  list($aclFrom, $aclWhere) = CRM_Contact_BAO_Contact_Permission::cacheClause('contact_a');
  $sql = "SELECT contact_a.id, contact_a.display_name
          FROM civicrm_contact contact_a
          {$aclFrom}
          WHERE contact_a.contact_type = 'Individual' AND contact_a.is_deleted = 0 AND contact_a.is_deceased = 0 AND {$aclWhere}
          ORDER BY contact_a.sort_name";
  $return = array();
  $dao = CRM_Core_DAO::executeQuery($sql);
  while($dao->fetch()) {
    if ($session->getLoggedInContactID() != $dao->id) {
      $return[$dao->id] = $dao->display_name . " (Lidnr: " . $dao->id . ")";
    }
  }
  return $return;
}

function spkaderfunctiesafdeling_log_activity_new_relationship($params) {
  $session = CRM_Core_Session::singleton();
  $activity['activity_type_id'] = (int) spkaderfunctiesafdeling_get_activity_type_id('Nieuwe relatie');
  $relationship_type = civicrm_api3('RelationshipType', 'getsingle', array('id' => $params['relationship_type_id']));
  $activity['subject'] = 'Nieuw relatie ('.$relationship_type['label_a_b'].')';
  $activity['target_contact_id'] = array(
    $params['contact_id_a'],
    $params['contact_id_b'],
  );
  civicrm_api3('Activity', 'create', $activity);
}

function spkaderfunctiesafdeling_log_activity_end_relationship($params) {
  $session = CRM_Core_Session::singleton();
  $activity['activity_type_id'] = (int) spkaderfunctiesafdeling_get_activity_type_id('Relatie beëindigd');
  $relationship_type = civicrm_api3('RelationshipType', 'getsingle', array('id' => $params['relationship_type_id']));
  $activity['subject'] = 'Relatie beëindigd ('.$relationship_type['label_a_b'].')';
  $activity['target_contact_id'] = array(
    $params['contact_id_a'],
    $params['contact_id_b'],
  );
  civicrm_api3('Activity', 'create', $activity);
}

function spkaderfunctiesafdeling_get_activity_type_id($name) {
  $activity_option_group = civicrm_api3('OptionGroup', 'getvalue', array('return' => 'id', 'name' => 'activity_type'));
  try {
    $activity = civicrm_api3('OptionValue', 'getsingle', array('option_group_id' => $activity_option_group, 'name' => $name));
    return $activity['value'];
  } catch (Exception $e) {
    $params = array();
    $params['name'] = $name;
    $params['label'] = $name;
    $params['option_group_id'] = $activity_option_group;
    civicrm_api3('OptionValue', 'create', $params);
    $activity = civicrm_api3('OptionValue', 'getsingle', array('option_group_id' => $activity_option_group, 'name' => $name));
    return $activity['value'];
  }
}