<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function p2pu_courses_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'general';
  $context->description = 'P2PU general course section context';
  $context->tag = 'P2PU course section';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~webcraft' => '~webcraft',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'popup_menu-primary-links' => array(
          'module' => 'popup_menu',
          'delta' => 'primary-links',
          'region' => 'primary_navigation',
          'weight' => 0,
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => 10,
          'region' => 'primary_navigation',
          'weight' => 1,
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'p2pu-context-course-section-general',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('P2PU course section');
  t('P2PU general course section context');

  $export['general'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'webcraft';
  $context->description = 'P2PU Webcraft course section context';
  $context->tag = 'P2PU course section';
  $context->conditions = array();
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-webcraft' => array(
          'module' => 'menu',
          'delta' => 'menu-webcraft',
          'region' => 'primary_navigation',
          'weight' => 0,
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'p2pu-context-course-section-webcraft',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('P2PU Webcraft course section context');
  t('P2PU course section');

  $export['webcraft'] = $context;
  return $export;
}
