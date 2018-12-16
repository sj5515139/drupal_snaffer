<?php
/**
 * @file
 * Contains Settings for miniOrange OTP Verification Module.
 */

 /**
  * Showing Settings form.
  */
function miniorange_otp_settings_information($form, &$form_state) {
  drupal_add_js(drupal_get_path('module', 'miniorange_otp') . '/js/toggle.js', 'file');
  if (!MiniorangeOtpUtilities::isCustomerRegistered()) {
    $form['header'] = array(
      '#markup' => '<center><h3>You need to register with miniOrange before using this module.</h3></center>',
    );
    return $form;
  }

  global $base_url;
  $conf_url = $base_url . '/?q=admin/config/people/miniorange_otp/configuration';
  $config_url = $base_url . '/?q=admin/config/people/accounts';
  $form['miniorange_otp_customer_validation'] = array(
    '#method' => 'post',
    '#type' => 'hidden',
    '#id' => 'mo_otp_verification_settings',
    '#value' => 'mo_customer_validation_settings',
  );

  $form['markup_1'] = array(
    '#markup' => '<h2>OTP VERIFICATION SETTINGS</h3><hr>',
  );

  $form['markup_2'] = array(
    '#markup' => 'By following these easy steps you can verify your users email or phone number instantly:<br><br>1. &nbsp Select the Verification method.<br>'
    . '2. &nbsp To Login immediately after the Registration process, select the "Immediate Login" option.<br>'
    . '3. &nbsp To configure your SMS/Email messages/gateway check under <a href="' . $conf_url . '">Configuration Tab</a>.<br>'
    . '4. &nbsp Save your settings.<br>'
    . '5. &nbsp Deselect the option: <b> "Require e-mail verification when a visitor creates an account" </b> under <b>"Registration and cancellation"</b> section from '
    . '<a href = "' . $config_url . '">here</a>. This will allow new user to set their own passwords while registration.<br>'
    . '6. &nbsp Log out and go to your registration or landing page for testing.<br><br>',
  );

  $form['miniorange_otp_options'] = array(
    '#type' => 'radios',
    '#tree' => TRUE,
    '#default_value' => variable_get('miniorange_otp_options', FALSE),
    '#title' => t('Drupal Default Registration Form'),
    '#options' => array(0 => t('Enable Email Verification'), 1 => t('Enable Phone Verification')),
  );

  $form['miniorange_otp_immediate_login_on_register'] = array(
    '#type' => 'checkbox',
    '#title' => t('Immediate Login'),
    '#default_value' => variable_get('miniorange_otp_immediate_login_on_register', FALSE),
    '#description' => t("If set, the user will be logged in immediately after registering."),
  );

  $form['miniorange_otp_settings_save_button'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('miniorange_otp_settings_save'),
  );
  return $form;
}


/**
 * Handling Save Settings tab.
 */
function miniorange_otp_settings_save($form, &$form_state) {

  global $base_url;
  $user_enabled = $form_state['values']['miniorange_otp_options'];
  $imm_login = $form_state['values']['miniorange_otp_immediate_login_on_register'];
  if ($imm_login == 1) {
    $im_login = TRUE;
  }
  else {
    $im_login = FALSE;
  }
  $logout_url = $base_url . '/?q=user/logout';
  variable_set('miniorange_otp_options', $user_enabled);
  variable_set('miniorange_otp_immediate_login_on_register', $im_login);
  $message = 'Settings saved successfully. You can go to your registration form page to test the plugin. <a href="' . $logout_url . '">Click here</a> to logout.';
  drupal_set_message(t($message));
}
