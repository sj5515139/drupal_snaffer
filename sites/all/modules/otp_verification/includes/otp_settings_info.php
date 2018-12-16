<?php
/**
 * @file
 * Contains miniOrange Settings class.
 */

/**
 * @file
 * This class represents settings for OTP verification.
 */
class MiniorangeOtpSettings {

  public $email;
  public $phone;
  /**
   * Check if customer is registered.
   */
  public static function miniorangeCustomerValidationIsCustomerRegistered() {
    $email = $this->email;
    $customer_key = $this->customerKey;
    if (!$email || !$customer_key || !is_numeric(trim($customer_key))) {
      return 0;
    }
    else {
      return 1;
    }
  }
  /**
   * Check if customer is validated.
   */
  public static function miniorangeIsCustomerValidated() {
    $email = $this->email;
    $customer_key = $this->customerKey;
    if (!$email || !$customer_key || !is_numeric(trim($customer_key))) {
      return 0;
    }
    else {
      return get_option('miniorange_customer_check_ln') ? get_option('miniorange_customer_check_ln') : 0;
    }
  }
  /**
   * Check if customer exists.
   */
  public static function checkCustomer() {
    $url = MiniorangeOtpConstants::$baseUrl . '/moas/rest/customer/check-if-exists';
    $ch = curl_init($url);
    $email = $this->email;

    $fields = array(
      'email' => $email,
    );
    $field_string = json_encode($fields);

    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, TRUE);
    curl_setopt($ch, CURLOPT_ENCODING, "");
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($ch, CURLOPT_AUTOREFERER, TRUE);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);

    curl_setopt($ch, CURLOPT_MAXREDIRS, 10);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array(
      'Content-Type: application/json',
      'charset: UTF - 8',
      'Authorization: Basic',
    ));
    curl_setopt($ch, CURLOPT_POST, TRUE);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $field_string);
    $content = curl_exec($ch);
    if (curl_errno($ch)) {
      echo 'Request Error:' . curl_error($ch);
      exit();
    }
    curl_close($ch);

    return $content;
  }

}
