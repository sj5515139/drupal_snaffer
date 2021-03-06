<?php
/**
 * @file
 * Contains Help & Troubleshooting for miniOrange OTP Verification Module.
 */

/**
 * Showing Help & Troubleshooting.
 */
function miniorange_otp_help_troubleshoot($form, &$form_state) {

  global $base_url;
  $config_url = $base_url . '/admin/config/people/accounts';

  $form['markup_1'] = array(
    '#markup' => 'If any section is not opening, press CTRL + F5 to clear cache.',
  );

  $form['markup_2'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle ="collapse" data-target = "#question1" >How does this plugin work?</a></h3>'
    . '<div id="question1" class="" ><ol><li>On submitting the registration form an Email/SMS with OTP is sent to the email address/mobile number provided by the user.</li>'
    . '<li>Once the OTP is entered, it is verified by our servers.</li></ol></div><hr><br>',
  );

  $form['markup_3'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question2" >How is this plugin better than other plugins available?</a></h3>'
    . '<div id="question2" class="" ><ol><li>Verification of users Email Address/Mobile Number during registration is a must these days. But what if you do not have your own SMTP/SMS gateway? With our plugin it is not necessary to have your own SMTP/SMS gateway. You can use our own gateways to send OTP over Email/SMS.</li>'
    . '<li>You can even use your own SMS/SMTP Gateway if you choose to do so.</li>'
    . '<li>Each Email is verified for it is authenticity by miniOrange servers.</li>'
    . '<li>Easy and hassle free setup. No SMTP/SMS gateway configuration required. You just need to choose your registration form and you are good to go.</li>'
    . '<li>Customizable Email/SMS Templates.</li></ol></div><hr><br>',
  );

  $form['markup_4'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question3" >My Registration form is missing from the list</a></h3>'
    . '<div id="question3" class="" ><ol>We are actively adding support for more forms. Please contact us using the support form on your right or email us at <b>info@miniorange.com</b>.<br>'
    . 'While contacting us please include enough information about your registration form and how you intend to use this plugin. We will respond promptly.</ol></div>'
    . '<hr><br>',
  );

  $form['markup_5'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question4" >How do I integrate the plugin with my own custom Registration Form?</a></h3>'
    . '<div id="question4" class="" ><ol>Please contact us using the support form on your right or email us at <b>info@miniorange.com</b>.<br>'
    . 'While contacting us please include enough information about your registration form and how you intend to use this plugin. We will respond promptly.</ol></div>'
    . '<hr><br>',
  );

  $form['markup_6'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question5" >How to enable PHP cURL extension? (Pre-requisite)</a></h3>'
    . '<div id="question5" class="" ><ol>cURL is enabled by default but in case you have disabled it, follow the steps to enable it<br><br>'
    . '<li>Open php.ini(it is usually in /etc/ or in php folder on the server).</li>'
    . '<li>Search for extension=php_curl.dll. Uncomment it by removing the semi-colon( ; ) in front of it.</li>'
    . '<li>Restart the Apache Server.</li><br>'
    . 'For any further queries, please submit a query on right hand side in our <b>Support Section</b>.</ol></div><hr><br>',
  );

  $form['markup_7'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question6" >I am getting this error. What do I do?<br>[ curl_setopt(): CURLOPT_FOLLOWLOCATION cannot be activated when an open_basedir is set. ] </a></h3>'
    . ' <div id="question6" class="" ><ol>Just set safe_mode = Off in your php.ini file (it is usually in /etc/ on the server). If that is already off, then look around for the open_basedir in the php.ini file, and change it to open_basedir = .'
    . '</ol></div><hr><br>',
  );

  $form['markup_8'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question6" >I am getting this Notice. What should I do?<br>[ Notice: Undefined index: pass ] </a></h3>'
    . ' <div id="question7" class="" ><ol>Unselect the <b>"Require e-mail verification when a visitor creates an account"</b> from the Drupal Configuration Menu -> Account Settings -> Registration and cancellation or <a href="' . $config_url . '">here</a>. '
    . '</ol></div><hr><br>',
  );

  $form['markup_9'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question6" >I am not able to set a password on creating a new account. What should I do?<br></a></h3>'
    . ' <div id="question8" class="" ><ol>Unselect the <b>"Require e-mail verification when a visitor creates an account"</b> from the Drupal Configuration Menu -> Account Settings -> Registration and cancellation or <a href="' . $config_url . '">here</a>. '
    . '</ol></div><hr><br>',
  );

  $form['markup_10'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question7" >I did not receive OTP. What should I do?</a></h3>'
    . '<div id="question9" class="" ><ol>Use the Resend OTP option to get an additional OTP. Please make sure you did not enter the first OTP you received if you selected Resend OTP option to get an additional OTP. Enter the latest OTP since the previous ones expire once you click on Resend OTP. <br> <br>'
    . 'If OTP sent on your email address are not working, please verify your account using your mobile number. You will get an OTP on your mobile number which you need to enter on the page. If none of the above works, please contact us using the Support form on the right.</ol></div>'
    . '<hr><br>',
  );

  $form['markup_11'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question8" >After entering OTP, I get Invalid OTP. What should I do?</a></h3>'
    . '<div id="question10" class="" ><ol>The OTP is sent as an email to your email address with which you have registered. If you cannot see the email from miniOrange in your mails, please make sure to check your SPAM folder.<br> <br>'
    . 'If you do not see an email even in SPAM folder, please verify your account using your mobile number. You will get an OTP on your mobile number which you need to enter on the page. If none of the above works, please contact us using the Support form on the right.</ol></div>'
    . '<hr><br>',
  );

  $form['markup_12'] = array(
    '#markup' => '<h3><a class="registration_question" data-toggle = "collapse" data-target = "#question9" >I forgot the password of my miniOrange account. How can I reset it?</a></h3>'
    . '<div id="question11" class="" ><ol>There are two cases according to the page you see -<br><br>'
    . '<li><b>Login with miniOrange</b> screen: You should click on <b>forgot password</b> link. You will get your new password on your email address which you have registered with miniOrange . Now you can login with the new password.</li>'
    . '<li><b>Register with miniOrange</b> screen: Enter your email ID and any random password in <b>password</b> and <b>confirm password</b> input box. This will redirect you to <b>Login with miniOrange</b> screen. Now follow first step.</li><br></ol></div><hr><br>',
  );

  return $form;
}
