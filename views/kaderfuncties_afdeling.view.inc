<?php

$drupalConfig = SpKaderfunctiesAfdelingConfigDrupal::getInstance();
$civicrmConfig = SpKaderfunctiesAfdelingConfigCiviCRM::getInstance();

$view = new view();
$view->name = 'kaderfuncties_afdeling';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'Kaderfuncties afdeling';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Kaderfuncties afdeling';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = $drupalConfig->getRolesWithAccess();
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Voet: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['empty'] = TRUE;
$handler->display->display_options['footer']['area']['content'] = '<ul class="tabs"><li class="add"><a href="'.url('kaderfuncties-afdeling/nieuw').'"><span class="icon add"></span>Voeg kaderfunctie toe</a></li></ul>';
$handler->display->display_options['footer']['area']['format'] = 'filtered_html';
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['label'] = 'Geen resultaten';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = '<p>Er zijn geen kaderfuncties om te tonen. Je moet ingelogd zijn als voorzitter of organisatiesecretaris om hier een overzicht te zien van actieve kaderfuncties voor jouw afdeling.</p>';
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Relationship: CiviCRM Contacts: CiviCRM Relationship (starting from contact A) */
$handler->display->display_options['relationships']['relationship_id_a']['id'] = 'relationship_id_a';
$handler->display->display_options['relationships']['relationship_id_a']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['relationship_id_a']['field'] = 'relationship_id_a';
$handler->display->display_options['relationships']['relationship_id_a']['relationship'] = 'drupal_id';
$handler->display->display_options['relationships']['relationship_id_a']['label'] = 'Voorzittersrelatie';
$handler->display->display_options['relationships']['relationship_id_a']['required'] = TRUE;
$handler->display->display_options['relationships']['relationship_id_a']['relationship_type'] = '0';
/* Relationship: CiviCRM Relationships: Contact ID B */
$handler->display->display_options['relationships']['contact_id_b_']['id'] = 'contact_id_b_';
$handler->display->display_options['relationships']['contact_id_b_']['table'] = 'civicrm_relationship';
$handler->display->display_options['relationships']['contact_id_b_']['field'] = 'contact_id_b_';
$handler->display->display_options['relationships']['contact_id_b_']['relationship'] = 'relationship_id_a';
$handler->display->display_options['relationships']['contact_id_b_']['label'] = 'Afdeling';
$handler->display->display_options['relationships']['contact_id_b_']['required'] = TRUE;
/* Relationship: CiviCRM Contacts: CiviCRM Relationship (starting from Contact B) */
$handler->display->display_options['relationships']['relationship_id_b']['id'] = 'relationship_id_b';
$handler->display->display_options['relationships']['relationship_id_b']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['relationship_id_b']['field'] = 'relationship_id_b';
$handler->display->display_options['relationships']['relationship_id_b']['relationship'] = 'contact_id_b_';
$handler->display->display_options['relationships']['relationship_id_b']['label'] = 'Relatie vanuit afdeling';
$handler->display->display_options['relationships']['relationship_id_b']['required'] = TRUE;
$handler->display->display_options['relationships']['relationship_id_b']['relationship_type'] = '0';
/* Relationship: CiviCRM Relationships: Contact ID A */
$handler->display->display_options['relationships']['contact_id_a_']['id'] = 'contact_id_a_';
$handler->display->display_options['relationships']['contact_id_a_']['table'] = 'civicrm_relationship';
$handler->display->display_options['relationships']['contact_id_a_']['field'] = 'contact_id_a_';
$handler->display->display_options['relationships']['contact_id_a_']['relationship'] = 'relationship_id_b';
$handler->display->display_options['relationships']['contact_id_a_']['label'] = 'Kaderlid';
$handler->display->display_options['relationships']['contact_id_a_']['required'] = TRUE;
/* Veld: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['relationship'] = 'contact_id_a_';
$handler->display->display_options['fields']['id']['label'] = 'Lidnummer';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Veld: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name_1']['id'] = 'display_name_1';
$handler->display->display_options['fields']['display_name_1']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name_1']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name_1']['relationship'] = 'contact_id_a_';
$handler->display->display_options['fields']['display_name_1']['label'] = 'Naam';
$handler->display->display_options['fields']['display_name_1']['link_to_civicrm_contact'] = 0;
/* Veld: CiviCRM Phone Details: Phone Number */
$handler->display->display_options['fields']['phone']['id'] = 'phone';
$handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone']['field'] = 'phone';
$handler->display->display_options['fields']['phone']['relationship'] = 'contact_id_a_';
$handler->display->display_options['fields']['phone']['label'] = 'Telefoon';
$handler->display->display_options['fields']['phone']['location_type'] = '0';
$handler->display->display_options['fields']['phone']['location_op'] = '0';
$handler->display->display_options['fields']['phone']['is_primary'] = 1;
$handler->display->display_options['fields']['phone']['phone_type'] = '0';
/* Veld: CiviCRM Email: Email Address */
$handler->display->display_options['fields']['email']['id'] = 'email';
$handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['email']['field'] = 'email';
$handler->display->display_options['fields']['email']['relationship'] = 'contact_id_a_';
$handler->display->display_options['fields']['email']['label'] = 'Email';
$handler->display->display_options['fields']['email']['location_type'] = '0';
$handler->display->display_options['fields']['email']['location_op'] = '0';
$handler->display->display_options['fields']['email']['is_primary'] = 1;
/* Veld: CiviCRM Relationship Type: Label a-b */
$handler->display->display_options['fields']['label_a_b']['id'] = 'label_a_b';
$handler->display->display_options['fields']['label_a_b']['table'] = 'civicrm_relationship_type';
$handler->display->display_options['fields']['label_a_b']['field'] = 'label_a_b';
$handler->display->display_options['fields']['label_a_b']['relationship'] = 'relationship_id_b';
$handler->display->display_options['fields']['label_a_b']['label'] = 'Functie';
/* Veld: CiviCRM Relationships: Start Date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['start_date']['field'] = 'start_date';
$handler->display->display_options['fields']['start_date']['relationship'] = 'relationship_id_b';
$handler->display->display_options['fields']['start_date']['label'] = 'Sinds';
$handler->display->display_options['fields']['start_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['start_date']['custom_date_format'] = 'd-m-Y';
$handler->display->display_options['fields']['start_date']['second_date_format'] = 'html5_tools_iso8601';
/* Veld: CiviCRM Relationships: Relationship ID */
$handler->display->display_options['fields']['id_1']['id'] = 'id_1';
$handler->display->display_options['fields']['id_1']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['id_1']['field'] = 'id';
$handler->display->display_options['fields']['id_1']['relationship'] = 'relationship_id_b';
$handler->display->display_options['fields']['id_1']['label'] = '';
$handler->display->display_options['fields']['id_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['id_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id_1']['separator'] = '';
/* Veld: CiviCRM Relationships: Relationship Type ID */
$handler->display->display_options['fields']['relationship_type_id']['id'] = 'relationship_type_id';
$handler->display->display_options['fields']['relationship_type_id']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['relationship_type_id']['field'] = 'relationship_type_id';
$handler->display->display_options['fields']['relationship_type_id']['relationship'] = 'relationship_id_b';
$handler->display->display_options['fields']['relationship_type_id']['label'] = '';
$handler->display->display_options['fields']['relationship_type_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['relationship_type_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['relationship_type_id']['separator'] = '';
/* Veld: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = '';
$handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = 'kaderfuncties-afdeling/[id_1]/beeindig';
$handler->display->display_options['fields']['php']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_value'] = 'return spkaderfunctiesafdeling_views_beeindig($row->relationship_type_id, $row->id_1);';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Sort criterion: CiviCRM Relationships: Relationship Type A-to-B */
$handler->display->display_options['sorts']['relationship_type']['id'] = 'relationship_type';
$handler->display->display_options['sorts']['relationship_type']['table'] = 'civicrm_relationship';
$handler->display->display_options['sorts']['relationship_type']['field'] = 'relationship_type';
$handler->display->display_options['sorts']['relationship_type']['relationship'] = 'relationship_id_b';
/* Sort criterion: CiviCRM Contacts: Sort Name */
$handler->display->display_options['sorts']['sort_name']['id'] = 'sort_name';
$handler->display->display_options['sorts']['sort_name']['table'] = 'civicrm_contact';
$handler->display->display_options['sorts']['sort_name']['field'] = 'sort_name';
$handler->display->display_options['sorts']['sort_name']['relationship'] = 'contact_id_a_';
/* Contextual filter: CiviCRM Contacts: Contact ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['relationship'] = 'contact_id_b_';
$handler->display->display_options['arguments']['id']['exception']['title'] = 'Alle';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Gebruiker: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current']['value'] = '1';
$handler->display->display_options['filters']['uid_current']['group'] = 1;
/* Filter criterion: CiviCRM Relationships: Relationship Type A-to-B */
$handler->display->display_options['filters']['relationship_type']['id'] = 'relationship_type';
$handler->display->display_options['filters']['relationship_type']['table'] = 'civicrm_relationship';
$handler->display->display_options['filters']['relationship_type']['field'] = 'relationship_type';
$handler->display->display_options['filters']['relationship_type']['relationship'] = 'relationship_id_a';
$handler->display->display_options['filters']['relationship_type']['value'] = $civicrmConfig->getVoorzitterRelationshipTypes();
$handler->display->display_options['filters']['relationship_type']['group'] = 1;
/* Filter criterion: CiviCRM Relationships: Is Relationship Active */
$handler->display->display_options['filters']['is_active']['id'] = 'is_active';
$handler->display->display_options['filters']['is_active']['table'] = 'civicrm_relationship';
$handler->display->display_options['filters']['is_active']['field'] = 'is_active';
$handler->display->display_options['filters']['is_active']['relationship'] = 'relationship_id_b';
$handler->display->display_options['filters']['is_active']['value'] = '1';
$handler->display->display_options['filters']['is_active']['group'] = 1;
/* Filter criterion: CiviCRM Relationships: End Date */
$handler->display->display_options['filters']['end_date']['id'] = 'end_date';
$handler->display->display_options['filters']['end_date']['table'] = 'civicrm_relationship';
$handler->display->display_options['filters']['end_date']['field'] = 'end_date';
$handler->display->display_options['filters']['end_date']['relationship'] = 'relationship_id_b';
$handler->display->display_options['filters']['end_date']['operator'] = 'empty';
$handler->display->display_options['filters']['end_date']['group'] = 1;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'kaderfuncties-afdeling';
$translatables['kaderfuncties_afdeling'] = array(
  t('Master'),
  t('Kaderfuncties afdeling'),
  t('more'),
  t('Apply'),
  t('Opnieuw instellen'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Geen resultaten'),
  t('<p>Er zijn geen kaderfuncties om te tonen. Je moet ingelogd zijn als voorzitter of organisatiesecretaris om hier een overzicht te zien van actieve kaderfuncties voor jouw afdeling.</p>'),
  t('Drupal User'),
  t('Voorzittersrelatie'),
  t('Afdeling'),
  t('Relatie vanuit afdeling'),
  t('Kaderlid'),
  t('Lidnummer'),
  t('.'),
  t('Naam'),
  t('Telefoon'),
  t('Email'),
  t('Functie'),
  t('Sinds'),
  t('Page'),
);
