<?php

class SpKaderfunctiesAfdelingConfigDrupal {

  /**
   * Singleton instance
   *
   * @var SpKaderfunctiesAfdelingConfigDrupal
   */
  private static $singleton;

  /**
   * Drupal roles which have access to the view Kaderfunctie
   *
   * @var array
   */
  private $rolesWithAccess = array();

  /**
   * Returns an instance of SpKaderfunctiesAfdelingConfigDrupal
   *
   * Singeton
   *
   * @return \SpKaderfunctiesAfdelingConfigDrupal
   */
  public static function getInstance() {
    if (!self::$singleton) {
      self::$singleton = new SpKaderfunctiesAfdelingConfigDrupal();
    }
    return self::$singleton;
  }

  private function __construct() {
    $this->rolesWithAccess[DRUPAL_AUTHENTICATED_RID] = DRUPAL_AUTHENTICATED_RID;
  }

  /**
   * Returns an array with drupal role ids which should have access to the view
   *
   * @return array
   */
  public function getRolesWithAccess() {
    return $this->rolesWithAccess;
  }

}