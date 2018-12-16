<?php
/**
 * @file
 * This file is part of miniOrange OTP Verification plugin.
 */

/**
 * OTP Utilities Class.
 */
class MiniorangeOtpUtilities {

  /**
   * Check if curl is installed.
   */
  public static function isCurlInstalled() {
    if (in_array('curl', get_loaded_extensions())) {
      return 1;
    }
    else {
      return 0;
    }
  }
  /**
   * Check if customer is registered.
   */
  public static function isCustomerRegistered() {
    if (variable_get('miniorange_otp_customer_admin_email', NULL) == NULL ||
    variable_get('miniorange_otp_customer_id', NULL) == NULL ||
    variable_get('miniorange_otp_customer_admin_token', NULL) == NULL ||
    variable_get('miniorange_otp_customer_api_key', NULL) == NULL) {
      return FALSE;
    }
    return TRUE;
  }

  /**
   * Call Service function for customer check.
   */
  public static function callService($customer_id, $api_key, $url, $field_string) {
    if (!self::isCurlInstalled()) {
      return json_encode(array(
        "status" => 'CURL_ERROR',
        "message" => 'PHP cURL extension is not installed or disabled.',
      ));
    }

    $ch = curl_init($url);
    $current_time_in_millis = round(microtime(TRUE) * 1000);
    $string_to_hash = $customer_id . number_format($current_time_in_millis, 0, '', '') . $api_key;
    $hash_value = hash("sha512", $string_to_hash);
    $customer_key_header = "Customer-Key: " . $customer_id;
    $timestamp_header = "Timestamp: " . number_format($current_time_in_millis, 0, '', '');
    $authorization_header = "Authorization: " . $hash_value;
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, TRUE);
    curl_setopt($ch, CURLOPT_ENCODING, "");
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($ch, CURLOPT_AUTOREFERER, TRUE);
    // Required for https urls.
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);
    curl_setopt($ch, CURLOPT_MAXREDIRS, 10);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array(
      "Content-Type: application/json",
      $customer_key_header,
      $timestamp_header,
      $authorization_header,
    ));
    curl_setopt($ch, CURLOPT_POST, TRUE);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $field_string);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);
    curl_setopt($ch, CURLOPT_TIMEOUT, 20);
    $content = curl_exec($ch);
    if (curl_errno($ch)) {
      return json_encode(array(
        "status" => 'CURL_ERROR',
        "message" => curl_errno($ch),
      ));
    }
    curl_close($ch);
    return json_decode($content);
  }

  public static function sendToken($otp_options, $email, $phone){
    $url = MiniorangeOtpConstants::$baseUrl . '/moas/api/auth/challenge';
    $ch = curl_init($url);

    $api_key = variable_get('miniorange_otp_customer_api_key', NULL);
    $customer_key = variable_get('miniorange_otp_customer_id', NULL);

    // Current time in milliseconds since midnight, January 1, 1970 UTC.
    $current_time_in_millis = round(microtime(TRUE) * 1000);

    // Creating the Hash using SHA-512 algorithm.
    $string_to_hash = $customer_key . $current_time_in_millis . $api_key;
    $hash_value = hash("sha512", $string_to_hash);

    $customer_key_header = "Customer-Key: " . $customer_key;
    $timestamp_header = "Timestamp: " . $current_time_in_millis;
    $authorization_header = "Authorization: " . $hash_value;

    if($otp_options == 0){
      $fields = array(
        'customerKey' => $customer_key,
        'email' => $email,
        'authType' => 'EMAIL',
        'transactionName' => 'Drupal OTP Verification',
      );
    }
    if($otp_options == 1){
      $fields = array(
        'customerKey' => $customer_key,
        'phone' => $phone,
        'authType' => 'SMS',
        'transactionName' => 'Drupal OTP Verification',
      );
    }
    $field_string = json_encode($fields);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, TRUE);
    curl_setopt($ch, CURLOPT_ENCODING, "");
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($ch, CURLOPT_AUTOREFERER, TRUE);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);
    curl_setopt($ch, CURLOPT_MAXREDIRS, 10);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array("Content-Type: application/json", $customer_key_header, $timestamp_header, $authorization_header,
    ));
    curl_setopt($ch, CURLOPT_POST, TRUE);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $field_string);

    $content = curl_exec($ch);
    $trans_status = json_decode($content)->status;
    $tx_id = json_decode($content)->txId;
    curl_close($ch);
	return array($trans_status, $tx_id);
    }
}
