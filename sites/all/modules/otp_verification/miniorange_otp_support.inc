<?php
/**
 * @file
 * Contains support form for miniOrange OTP Verification Module.
 */

/**
 * Showing Support form info.
 */
function miniorange_otp_support($form, &$form_state) {

  $form['markup_1'] = array(
    '#markup' => '<h3>Support</h3><div>Need any help? Just send us a query so we can help you.<br /><br /></div>',
  );

  $form['miniorange_otp_email_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Address'),
    '#attributes' => array('placeholder' => 'Enter your email'),
  );

  $form['miniorange_otp_phone_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone number'),
    '#attributes' => array('placeholder' => 'Enter your phone number'),
  );

  $form['miniorange_otp_support_query'] = array(
    '#type' => 'textarea',
    '#title' => t('Query'),
    '#cols' => '10',
    '#rows' => '5',
    '#attributes' => array('placeholder' => 'Write your query here'),
    '#required' => TRUE,
  );

  $form['miniorange_otp_support_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit Query'),
    '#submit' => array('miniorange_otp_send_query'),
  );

  return $form;

}

/**
 * Send support query.
 */
function miniorange_otp_send_query($form, &$form_state) {
  $email = $form['miniorange_otp_email_address']['#value'];
  $phone = $form['miniorange_otp_phone_number']['#value'];
  $query = $form['miniorange_otp_support_query']['#value'];
  $support = new MiniOrangeOtpSupport($email, $phone, $query);
  $support_response = $support->sendSupportQuery();
  if ($support_response) {
    drupal_set_message(t('Support query successfully sent'));
  }
  else {
    drupal_set_message(t('Error sending support query'), 'error');
  }
}
