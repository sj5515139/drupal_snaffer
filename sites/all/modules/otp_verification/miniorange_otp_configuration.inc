<?php
/**
 * @file
 * Contains Configuration for miniOrange OTP Verification Module.
 */

require_once 'miniorange_otp_licensing_plan.inc';
/**
 * Showing Configuration form.
 */
function miniorange_otp_configuration($form, &$form_state) {
  global $base_url, $_miniorange_otp_msg;
  if (!MiniorangeOtpUtilities::isCustomerRegistered()) {
    $form['header'] = array(
      '#markup' => '<center><h3>You need to register with miniOrange before using this module.</h3></center>',
    );
    return $form;
  }

  miniorange_otp_handle_mo_check_ln($_miniorange_otp_msg);
  $smstemp = MiniorangeOtpConstants::$baseUrl . '/moas/showsmstemplate';
  $smsconfig = MiniorangeOtpConstants::$baseUrl . '/moas/smsconfig';
  $emailtemp = MiniorangeOtpConstants::$baseUrl . '/moas/showemailtemplate';
  $emailconfig = MiniorangeOtpConstants::$baseUrl . '/moas/configureSMTP';
  $var = variable_get('mo_customer_check_ln');

  $pcode = MiniorangeOtpcustomer::$pcode;
  $bcode = MiniorangeOtpcustomer::$bcode;

  $form['markup_1'] = array(
    '#markup' => '<h2>SMS & EMAIL CONFIGURATION</h2><hr>',
  );

  $form['markup_2'] = array(
    '#markup' => 'Look at the sections below to customize the Email and SMS that you receive:<br>'
    . '1. &nbsp <a href="#sms">Custom SMS Template</a> : Change the text of the message that you receive on your phones.<br>'
    . '2. &nbsp <a href="#sms">Custom SMS Gateway</a> : You can configure settings to use your own SMS gateway.<br>'
    . '3. &nbsp <a href="#email">Custom Email Template</a> : Change the text of the email that you receive.<br>'
    . '4. &nbsp <a href="#email">Custom Email Gateway</a> : You can configure settings to use your own Email gateway.<br><br>',
  );

  $form['markup_3'] = array(
    '#markup' => '<a class="form_query" data-toggle = "collapse" data-target = "#q1">[ How can I change the SenderID/Number of the SMS I receive? ]</a>'
    . '<div id="q1" class="" ><ol><li>SenderID/Number is gateway specific. You will need to use your own SMS gateway for this.</li></ol></div><br>',
  );

  $form['markup_4'] = array(
    '#markup' => '<a class="form_query" data-toggle = "collapse" data-target = "#q2">[ How can I change the Sender Email of the Email I receive? ]</a><br>'
    . '<div id="q2" class="" ><ol><li>Sender Email is gateway specific. You will need to use your own Email gateway for this.</li></ol></div><br>',
  );

  if (!$var == $pcode || !$var == $bcode) {
    $form['markup_5'] = array(
      '#markup' => '<h2>SMS CONFIGURATION (Premium Feature)</h2><hr>',
    );
    $image1_options = array(
      'path' => $base_url . '/' . drupal_get_path('module', 'miniorange_otp') . '/includes/images/smsTemplateOb.jpg',
      'alt' => 'Custom SMS Template',
    );
    $image1 = theme('image', $image1_options);
    $form['image1']['image'] = array(
      '#markup' => 'Custom SMS Template <br>' . $image1 . '<br>'
      . '<a class="btn btn-primary btn-large" style="padding:5px;" disabled="true" >Change SMS Template</a></h4><br><br><hr>',
    );

    $image2_options = array(
      'path' => $base_url . '/' . drupal_get_path('module', 'miniorange_otp') . '/includes/images/smsGatewayOb.jpg',
      'alt' => 'Custom SMS Gateway',
    );
    $image2 = theme('image', $image2_options);
    $form['image2']['image'] = array(
      '#markup' => 'Custom SMS Gateway <br>' . $image2 . '<br>'
      . '<a class="btn btn-primary btn-large" style="padding:5px;" disabled="true" >Change SMS Gateway</a></h4><br><br><hr>',
    );

    $form['markup_8'] = array(
      '#markup' => '<h2>Email CONFIGURATION (Premium Feature)</h2><hr>',
    );

    $image3_options = array(
      'path' => $base_url . '/' . drupal_get_path('module', 'miniorange_otp') . '/includes/images/emailTemplateOb.jpg',
      'alt' => 'Custom Email Template',
    );
    $image3 = theme('image', $image3_options);
    $form['image3']['image'] = array(
      '#markup' => 'Custom Email Template <br>' . $image3 . '<br>'
      . '<a class="btn btn-primary btn-large" style="padding:5px;" disabled="true">Change Email Template</a></h4><br><br><hr>',
    );

    $image4_options = array(
      'path' => $base_url . '/' . drupal_get_path('module', 'miniorange_otp') . '/includes/images/emailGatewayOb.jpg',
      'alt' => 'Custom Email Gateway',
    );
    $image4 = theme('image', $image4_options);
    $form['image4']['image'] = array(
      '#markup' => 'Custom Email Gateway <br>' . $image4 . '<br>'
      . '<a class="btn btn-primary btn-large" style="padding:5px;" disabled="true">Change Email Gateway</a></h4><br><br><hr>',
    );
    return $form;
  }
  elseif ($var == $pcode || $var == $bcode) {
    $form['markup_5'] = array(
      '#markup' => '<h2>SMS CONFIGURATION</h2><hr>',
    );
    $image1_options = array(
      'path' => $base_url . '/' . drupal_get_path('module', 'miniorange_otp') . '/includes/images/smsTemplate.jpg',
      'alt' => 'Custom SMS Template',
    );
    $image1 = theme('image', $image1_options);
    $form['image1']['image'] = array(
      '#markup' => 'Custom SMS Template <br>' . $image1 . '<br>'
      . '<a class="btn btn-primary btn-large" style="padding:5px;"  href="' . $smstemp . '">Change SMS Template</a></h4><br><hr>',
    );

    $image2_options = array(
      'path' => $base_url . '/' . drupal_get_path('module', 'miniorange_otp') . '/includes/images/smsGateway.jpg',
      'alt' => 'Custom SMS Gateway',
    );
    $image2 = theme('image', $image2_options);
    $form['image2']['image'] = array(
      '#markup' => 'Custom SMS Gateway <br>' . $image2 . '<br>'
      . '<a class="btn btn-primary btn-large" style="padding:5px;" href="' . $smsconfig . '">Change SMS Gateway</a></h4><br><hr>',
    );

    $form['markup_8'] = array(
      '#markup' => '<h2>Email CONFIGURATION</h2><hr>',
    );

    $image3_options = array(
      'path' => $base_url . '/' . drupal_get_path('module', 'miniorange_otp') . '/includes/images/emailTemplate.jpg',
      'alt' => 'Custom Email Template',
    );
    $image3 = theme('image', $image3_options);
    $form['image3']['image'] = array(
      '#markup' => 'Custom Email Template <br>' . $image3 . '<br>'
      . '<a class="btn btn-primary btn-large" style="padding:5px;"  href="' . $emailtemp . '">Change Email Template</a></h4><br><hr>',
    );

    $image4_options = array(
      'path' => $base_url . '/' . drupal_get_path('module', 'miniorange_otp') . '/includes/images/emailGateway.jpg',
      'alt' => 'Custom Email Gateway',
    );
    $image4 = theme('image', $image4_options);
    $form['image4']['image'] = array(
      '#markup' => 'Custom Email Gateway <br>' . $image4 . '<br>'
      . '<a class="btn btn-primary btn-large" style="padding:5px;"  href="' . $emailconfig . '">Change Email Gateway</a></h4><br><hr>',
    );
    return $form;
  }
}
