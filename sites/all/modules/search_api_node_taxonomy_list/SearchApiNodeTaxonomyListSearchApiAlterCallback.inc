<?php
/**
  * @file
  * Provides data alteration allowing for a field with all taxonomy tids
  *
  */
class SearchApiNodeTaxonomyListSearchApiAlterCallback extends SearchApiAbstractAlterCallback {
  public function supportsIndex(SearchApiIndex $index) {
    return $index->entity_type == 'node';
  }

  public function alterItems(array &$items) {
    $fields = field_info_fields();
    foreach ($items as $id => &$item) {
      $item->search_api_node_taxonomy_list_tid = array();
      $lang = $item->language;
      foreach($fields as $field) {
        if (isset($item->{$field['field_name']}) &&
            ($field['type'] == 'taxonomy_term_reference')) {
          foreach($item->{$field['field_name']}[$lang] as $value) {
            $term = taxonomy_term_load($value['tid']);
            $item->search_api_node_taxonomy_list_tid[] = $value['tid'];
            $item->search_api_node_taxonomy_list_term[] = $term->name;
            foreach(taxonomy_get_parents_all($term->tid) as $parent_term) {
              $item->search_api_node_taxonomy_list_parents_tid[] = $parent_term->tid;
              $item->search_api_node_taxonomy_list_parents_term[] = $parent_term->name;
            }
          }
        }
      }
    }   
  }

  public function propertyInfo() {
    return array(
      'search_api_node_taxonomy_list_tid' => array(
        'label' => t('Taxonomy Terms Tid'),
        'type' => 'list<integer>',
        'description' => t('A list of all Taxonomy Terms Ids '),
      ),  
      'search_api_node_taxonomy_list_term' => array(
        'label' => t('Taxonomy Terms'),
        'type' => 'list<string>',
        'description' => t('A list of all Taxonomy Terms'),
      ),  
      'search_api_node_taxonomy_list_parents_tid' => array(
        'label' => t('Taxonomy Terms Tid w/parents'),
        'type' => 'list<integer>',
        'description' => t('A list of all Taxonomy Terms Ids and thier parent term ids'),
      ),  
      'search_api_node_taxonomy_list_parents_term' => array(
        'label' => t('Taxonomy Terms w/parents'),
        'type' => 'list<string>',
        'description' => t('A list of all Taxonomy Terms and the partents terms'),
      ),  
    );  
  }
}
