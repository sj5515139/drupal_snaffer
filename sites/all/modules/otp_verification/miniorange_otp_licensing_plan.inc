<?php
/**
 * @file
 * Contains Licensing information for miniOrange OTP Verification Module.
 */

 /**
  * Showing Licensing form info.
  */
function miniorange_otp_licensing_plan() {

  global $base_url;
  $support_url = $base_url . '/?q=admin/config/people/miniorange_otp/support';
  $var = variable_get('mo_customer_check_ln');
  $pcode = MiniorangeOtpCustomer::$pcode;
  $bcode = MiniorangeOtpCustomer::$bcode;
  $dyi_plan = "'drupal_otp_verification_basic_plan'";
  $premium_plan = "'drupal_otp_verification_premium_plan'";
  $quick_recharge = "'otp_recharge_plan'";
  $admin_username = "'" . variable_get('miniorange_otp_customer_admin_email', '') . "'";

  $form['markup_1'] = array(
    '#markup' => '<div class="mo_otp_table_layout">'
    . '<table class="mo_otp_local_pricing_table"> <h2>Licensing Plans</h2> <tr style="vertical-align:top;">',
  );

  $form['ok_got_it'] = array(
    '#name' => 'ok-got-it',
    '#type' => 'submit',
    '#value' => t('Ok, Got it'),
    '#submit' => array('miniorange_otp_mo_otp_ok_submit'),
    '#attributes' => array('style' => 'display:inline-block; display:inline-block; float: right;'),
  );

  $form['check_licence'] = array(
    '#name' => 'check_license',
    '#type' => 'submit',
    '#value' => t('Check Licence'),
    '#submit' => array('miniorange_otp_handle_mo_check_ln'),
    '#attributes' => array('style' => 'display:inline-block; display: inline-block;float: right;'),
  );

  if ($var == $pcode) {
    $form['markup_3'] = array(
      '#markup' => '<td><div class="mo_otp_local_thumbnail mo_otp_local_pricing_paid_tab">'
      . '<h3 class="mo_otp_local_pricing_header" style= text-align:center;>Do it yourself</h3>'
      . '<h4 class="mo_otp_local_pricing_sub_header" style="padding-bottom:5px !important; text-align:center;">'
      . '<a class="btn btn-primary btn-large" style="padding:5px; text-align:center;" onclick="payment(' . $dyi_plan . ',' . $admin_username . ');">Click to Upgrade</a>*</h4>'
      . '<p style=padding-bottom:-10px;><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style="padding:10px; text-align:center;" >$99 - One Time Payment<br><br>+</p>'
      . '<p style="padding:0px 50px;"><select class="mo-form-control" style="text-align:center; background-color: #337ab7; color: WHITE; padding:5px;width:100%;border-radius:2px;">'
      . '<option>$50 per 10k transaction**</option><br>'
      . '<option>$100 per 50k transaction**</option><br>'
      . '<option>$150 per 100k transaction**</option><br>'
      . '<option>$300 per 500k transaction**</option><br>'
      . '<option>$500 per 1million transaction**</option><br></select>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-bottom:5px; >[ This is for your own SMS/SMTP gateway ]<br/>[ You can refill at anytime ]<br/>[ To use miniOrange SMS/SMTP gateway, Contact Us* ]<br></p>'
      . '<p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-bottom:19px;>'
      . 'Features<br>'
      . 'Email Address Verification<br>Phone Number Verification<br>Custom Email Template<br>'
      . 'Custom SMS Template<br>Custom SMS/SMTP Gateway<br></p><p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-top:3px;>Basic Support by Email</p></div></td>',
    );

    $form['markup_4'] = array(
      '#markup' => '<td><div class="mo_otp_local_thumbnail mo_otp_local_pricing_free_tab">'
      . '<h3 class="mo_otp_local_pricing_header" style=text-align:center;>Premium</h3>'
      . '<h4 class="mo_otp_local_pricing_sub_header" style="padding-bottom:6px !important; text-align:center;">'
      . '<a class="btn btn-primary btn-large" style="padding:5px; text-align:center;"  onclick="payment(' . $quick_recharge . ',' . $admin_username . ');">Recharge</a>*</h4><p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style="padding:10px; text-align:center;">$199 + One Time Payment<br><br>+<br></p>'
      . '<p style="padding:0px 50px;"><select class="mo-form-control" style="text-align:center; background-color: #337ab7; color: WHITE; padding:5px;width:100%;border-radius:2px;">'
      . '<option>$50 per 10k transaction**</option>'
      . '<option>$100 per 50k transaction**</option>'
      . '<option>$150 per 100k transaction**</option>'
      . '<option>$300 per 500k transaction**</option>'
      . '<option>$500 per 1million transaction**</option></select>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-bottom:5px;>[ This is for your own SMS/SMTP gateway ]<br/>[ You can refill at anytime ]<br/>[ To use miniOrange SMS/SMTP gateway, Contact Us* ]</p>'
      . '<p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;>'
      . 'Features<br>'
      . 'Email Address Verification<br>Phone Number Verification<br>Custom Email Template<br>'
      . 'Custom SMS Template<br>Custom SMS/SMTP Gateway<br>Custom Integration/Work<br></p><hr>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-top:3px;>Premium Support Plans</p>'
      . '</div></td></tr></table>',
    );

    $form['markup_5'] = array(
      '#markup' => '*If you want to use <b>miniOrange SMS/SMTP gateway</b>, mail us at ' . l(t('info@miniorange.com'), 'mailto:info@miniorange.com', array('absolute' => TRUE))
      . 'or submit a support request using the support form under <a href = "' . $support_url . '">Support</a> Tab. We will get back to you promptly.<br><br>',
    );

    $form['markup_6'] = array(
      '#markup' => '**This is for your own SMS/SMTP gateway. If you want to use miniOrange SMS/SMTP gatewayor want more than 10k transactions,'
      . 'mail us at ' . l(t('info@miniorange.com'), 'mailto:info@miniorange.com', array('absolute' => TRUE)) . ' or submit a support request using the support form under <a href = "' . $support_url . '">Support</a> Tab',
    );

    return $form;
  }
  elseif ($var == $bcode) {
    $form['markup_3'] = array(
      '#markup' => '<td><div class="mo_otp_local_thumbnail mo_otp_local_pricing_paid_tab">'
      . '<h3 class="mo_otp_local_pricing_header" style= text-align:center;>Do it yourself</h3>'
      . '<h4 class="mo_otp_local_pricing_sub_header" style="padding-bottom:5px !important; text-align:center;">'
      . '<a class="btn btn-primary btn-large" style="padding:5px; text-align:center;" onclick="payment(' . $quick_recharge . ',' . $admin_username . ');">Recharge</a>*</h4>'
      . '<p style=padding-bottom:-10px;><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style="padding:10px; text-align:center;" >$99 - One Time Payment<br><br>+</p>'
      . '<p style="padding:0px 50px;"><select class="mo-form-control" style="text-align:center; background-color: #337ab7; color: WHITE; padding:5px;width:100%;border-radius:2px;">'
      . '<option>$50 per 10k transaction**</option><br>'
      . '<option>$100 per 50k transaction**</option><br>'
      . '<option>$150 per 100k transaction**</option><br>'
      . '<option>$300 per 500k transaction**</option><br>'
      . '<option>$500 per 1million transaction**</option><br></select>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-bottom:5px; >[ This is for your own SMS/SMTP gateway ]<br/>[ You can refill at anytime ]<br/>[ To use miniOrange SMS/SMTP gateway, Contact Us* ]<br></p>'
      . '<p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-bottom:19px;>'
      . 'Features<br>'
      . 'Email Address Verification<br>Phone Number Verification<br>Custom Email Template<br>'
      . 'Custom SMS Template<br>Custom SMS/SMTP Gateway<br></p><p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-top:3px;>Basic Support by Email</p></div></td>',
    );

    $form['markup_4'] = array(
      '#markup' => '<td><div class="mo_otp_local_thumbnail mo_otp_local_pricing_free_tab">'
      . '<h3 class="mo_otp_local_pricing_header" style=text-align:center;>Premium</h3>'
      . '<h4 class="mo_otp_local_pricing_sub_header" style="padding-bottom:6px !important; text-align:center;">'
      . '<a class="btn btn-primary btn-large" style="padding:5px; text-align:center;"  onclick="payment(' . $premium_plan . ',' . $admin_username . ');">Click to Upgrade</a>*</h4><p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style="padding:10px; text-align:center;">$199 + One Time Payment<br><br>+<br></p>'
      . '<p style="padding:0px 50px;"><select class="mo-form-control" style="text-align:center; background-color: #337ab7; color: WHITE; padding:5px;width:100%;border-radius:2px;">'
      . '<option>$50 per 10k transaction**</option>'
      . '<option>$100 per 50k transaction**</option>'
      . '<option>$150 per 100k transaction**</option>'
      . '<option>$300 per 500k transaction**</option>'
      . '<option>$500 per 1million transaction**</option></select>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-bottom:5px;>[ This is for your own SMS/SMTP gateway ]<br/>[ You can refill at anytime ]<br/>[ To use miniOrange SMS/SMTP gateway, Contact Us* ]</p>'
      . '<p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;>Features<br>'
      . 'Email Address Verification<br>Phone Number Verification<br>Custom Email Template<br>'
      . 'Custom SMS Template<br>Custom SMS/SMTP Gateway<br>Custom Integration/Work<br></p><hr>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-top:3px;>Premium Support Plans</p>'
      . '</div></td></tr></table>',
    );

    $form['markup_5'] = array(
      '#markup' => '*If you want to use <b>miniOrange SMS/SMTP gateway</b>, mail us at ' . l(t('info@miniorange.com'), 'mailto:info@miniorange.com', array('absolute' => TRUE))
      . ' or submit a support request using the support form under <a href = "' . $support_url . '">Support</a> Tab. We will get back to you promptly.<br><br>',
    );

    $form['markup_6'] = array(
      '#markup' => '**This is for your own SMS/SMTP gateway. If you want to use miniOrange SMS/SMTP gatewayor want more than 10k transactions,'
      . 'mail us at ' . l(t('info@miniorange.com'), 'mailto:info@miniorange.com', array('absolute' => TRUE)) . ' or submit a support request using the support form under <a href = "' . $support_url . '">Support</a> Tab',
    );

    return $form;
  }

  else {
    $form['markup_2'] = array(
      '#markup' => '<td><div class="mo_otp_local_thumbnail mo_otp_local_pricing_free_tab">'
      . '<h3 class="mo_otp_local_pricing_header" style=text-align:center;>Free<br>(You are automatically on this plan)</h3><br>'
      . '<h4 class="mo_otp_local_pricing_sub_header" style="padding-bottom:8px !important; text-align:center;"><hr>'
      . '<p class="mo_otp_local_pricing_text" style="padding:15px;padding-bottom:100px; text-align:center;">$0 - One Time Payment<br><br><br>( 10 SMS and 10 Email Transactions )</p>'
      . '<p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style="padding:5px;padding-bottom:50px;text-align:center;">Features<br><br>'
      . 'Email Address Verification<br>Phone Number Verification<p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-top:3px;>Basic Support by Email</p></div></td>',
    );

    $form['markup_3'] = array(
      '#markup' => '<td><div class="mo_otp_local_thumbnail mo_otp_local_pricing_paid_tab">'
      . '<h3 class="mo_otp_local_pricing_header" style= text-align:center;>Do it yourself</h3>'
      . '<h4 class="mo_otp_local_pricing_sub_header" style="padding-bottom:5px !important; text-align:center;">'
      . '<a class="btn btn-primary btn-large" style="padding:5px; text-align:center;" onclick="payment(' . $dyi_plan . ',' . $admin_username . ');">Click to Upgrade</a>*</h4>'
      . '<p style=padding-bottom:-10px;><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style="padding:10px; text-align:center;" >$99 - One Time Payment<br><br>+</p>'
      . '<p style="padding:0px 50px;"><select class="mo-form-control" style="text-align:center; background-color: #337ab7; color: WHITE; padding:5px;width:100%;border-radius:2px;">'
      . '<option>$50 per 10k transaction**</option><br>'
      . '<option>$100 per 50k transaction**</option><br>'
      . '<option>$150 per 100k transaction**</option><br>'
      . '<option>$300 per 500k transaction**</option><br>'
      . '<option>$500 per 1million transaction**</option><br></select>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-bottom:5px; >[ This is for your own SMS/SMTP gateway ]<br/>[ You can refill at anytime ]<br/>[ To use miniOrange SMS/SMTP gateway, Contact Us* ]<br></p>'
      . '<p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-bottom:19px;>Features<br>'
      . 'Email Address Verification<br>Phone Number Verification<br>Custom Email Template<br>'
      . 'Custom SMS Template<br>Custom SMS/SMTP Gateway<br></p><p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-top:3px;>Basic Support by Email</p></div></td>',
    );

    $form['markup_4'] = array(
      '#markup' => '<td><div class="mo_otp_local_thumbnail mo_otp_local_pricing_free_tab">'
      . '<h3 class="mo_otp_local_pricing_header" style=text-align:center;>Premium</h3>'
      . '<h4 class="mo_otp_local_pricing_sub_header" style="padding-bottom:6px !important; text-align:center;">'
      . '<a class="btn btn-primary btn-large" style="padding:5px; text-align:center;"  onclick="payment(' . $premium_plan . ',' . $admin_username . ');">Click to upgrade</a>*</h4><p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style="padding:10px; text-align:center;">$199 + One Time Payment<br><br>+<br></p>'
      . '<p style="padding:0px 50px;"><select class="mo-form-control" style="text-align:center; background-color: #337ab7; color: WHITE; padding:5px;width:100%;border-radius:2px;">'
      . '<option>$50 per 10k transaction**</option>'
      . '<option>$100 per 50k transaction**</option>'
      . '<option>$150 per 100k transaction**</option>'
      . '<option>$300 per 500k transaction**</option>'
      . '<option>$500 per 1million transaction**</option></select>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-bottom:5px;>[ This is for your own SMS/SMTP gateway ]<br/>[ You can refill at anytime ]<br/>[ To use miniOrange SMS/SMTP gateway, Contact Us* ]</p>'
      . '<p><hr></p>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;>Features<br>'
      . 'Email Address Verification<br>Phone Number Verification<br>Custom Email Template<br>'
      . 'Custom SMS Template<br>Custom SMS/SMTP Gateway<br>Custom Integration/Work<br></p><hr>'
      . '<p class="mo_otp_local_pricing_text" style=text-align:center;padding-top:3px;>Premium Support Plans</p>'
      . '</div></td></tr></table>',
    );
    $form['markup_5'] = array(
      '#markup' => '*If you want to use <b>miniOrange SMS/SMTP gateway</b>, mail us at ' . l(t('info@miniorange.com'), 'mailto:info@miniorange.com', array('absolute' => TRUE))
      . ' or submit a support request using the support form under <a href = "' . $support_url . '">Support</a> Tab. We will get back to you promptly.<br><br>',
    );

    $form['markup_6'] = array(
      '#markup' => '**This is for your own SMS/SMTP gateway. If you want to use miniOrange SMS/SMTP gateway or want more than 10k transactions,'
      . 'mail us at ' . l(t('info@miniorange.com'), 'mailto:info@miniorange.com', array('absolute' => TRUE)) . ' or submit a support request using the support form under <a href = "' . $support_url . '">Support</a> Tab',
    );

    return $form;
  }
}

/**
 * Check license.
 */
function miniorange_otp_handle_mo_check_ln($showmessage) {
  $challenge_otp = new MiniorangeOtpCustomer(NULL, NULL, NULL, NULL);
  $content = json_decode($challenge_otp->checkCustomerLn(), TRUE);

  if (strcasecmp($content['status'], 'SUCCESS') == 0) {
    $license_plan = $content['licensePlan'];
    array_key_exists('licensePlan', $content) && !MiniorangeOtpCustomer::moCheckEmptyOrNull($content['licensePlan']) ? variable_set('mo_customer_check_ln', base64_encode($content['licensePlan'])) : variable_set('mo_customer_check_ln', '');
    if ($showmessage) {
      array_key_exists('licensePlan', $content) && !MiniorangeOtpCustomer::moCheckEmptyOrNull($content['licensePlan']) ? drupal_set_message(t('Thank you, you have been upgraded to @license_name', array('@license_name' => $license_plan))) : drupal_set_message(t('You are on our FREE plan, check Licensing Tab to learn how to upgrade.'));

      if (array_key_exists('licensePlan', $content) && !MiniorangeOtpCustomer::moCheckEmptyOrNull($content['licensePlan'])) {
        variable_del('mo_customer_email_transactions_remaining');
        variable_del('mo_customer_phone_transactions_remaining');
        variable_del('mo_otp_plugin_version');
        variable_del('mo_customer_validation_transaction_message');
      }
    }
  }
  elseif (strcasecmp($content['status'], 'FAILED') == 0) {
    array_key_exists('licensePlan', $content) && !MiniorangeOtpCustomer::moCheckEmptyOrNull($content['licensePlan']) ? drupal_set_message(t('Thank you, you have been upgraded to @license_name', array('@license_name' => $license_plan))) : drupal_set_message(t('You are on our FREE plan, check Licensing Tab to learn how to upgrade.'));
  }
}

/**
 * Ok button.
 */
function miniorange_otp_mo_otp_ok_submit($showmessage) {
  global $base_url;
  drupal_goto($base_url . '/?q=admin/config/people/miniorange_otp/settings');
}
