<?php

class SpKaderfunctiesAfdelingConfigCiviCRM {

  /**
   * Singleton instance
   *
   * @var SpKaderfunctiesAfdelingConfigCiviCRM
   */
  private static $singleton;

  /**
   * Array with relationship type IDS of voorzitter, vervangend voorzitter en secretaris relationships
   *
   * @var array
   */
  private $voorzitterRelationshipTypeIds = array();

  private $contactSubTypeForButton = array();

  /**
   * Returns an instance of SpKaderfunctiesAfdelingConfigCiviCRM
   *
   * Singeton
   *
   * @return \SpKaderfunctiesAfdelingConfigCiviCRM
   */
  public static function getInstance() {
    if (!self::$singleton) {
      self::$singleton = new SpKaderfunctiesAfdelingConfigCiviCRM();
    }
    return self::$singleton;
  }

  private function __construct() {
    civicrm_initialize();

    $voorzitterRelationshipTypesNameAB = array('sprel_voorzitter_afdeling', 'sprel_vervangendvoorzitter_afdeling', 'sprel_organisatiesecretaris_afdeling', 'Gebruiker CiviCRM');
    $this->loadVoorzitterRelationshipTypes($voorzitterRelationshipTypesNameAB);

    $this->contactSubTypeForButton = array(
      'SP_Provincie',
      'SP_Regio',
      'SP_Afdeling',
      'SP_Werkgroep',
    );
  }

  /**
   * Return the relationship type ids for voorzitter, vervangend voorzitter en voor organisatie secretaris
   *
   * @return array
   */
  public function getVoorzitterRelationshipTypes() {
    return $this->voorzitterRelationshipTypeIds;
  }

  public function getContactSubTypesForButton() {
    return $this->contactSubTypeForButton;
  }

  private function loadVoorzitterRelationshipTypes($voorzitterRelationshipTypesNameAB) {
    $where = "";
    foreach($voorzitterRelationshipTypesNameAB as $name_a_b) {
      if (strlen($where)) {
        $where .= " OR ";
      }
      $where .= " `name_a_b` = '".$name_a_b."'";
    }
    if (strlen($where)) {
      $where = " (".$where.")";
    }
    $sql = "SELECT * FROM `civicrm_relationship_type` WHERE ".$where;
    $dao = CRM_Core_DAO::executeQuery($sql);

    while($dao->fetch()) {
      $this->voorzitterRelationshipTypeIds[$dao->id] = $dao->id;
    }
  }


}
