#include "extended_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_extended_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};
  int8_t status = sum_conditions(value_1, value_2, result);

  if (status == 1) {
    MATH_OPERATIONS(ADD);
    set_status(big_result, result, &status);
  }
  return status;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_extended_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};
  int8_t status = sub_conditions(value_1, value_2, result);

  if (status == 1) {
    MATH_OPERATIONS(SUB);
    set_status(big_result, result, &status);
  }
  return status;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_extended_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};
  int8_t status = mul_conditions(value_1, value_2, result);

  if (status == 1) {
    MATH_OPERATIONS(MUL);
  }
  result->bytes[SIGN] = value_1.bytes[SIGN] ^ value_2.bytes[SIGN];
  set_status(big_result, result, &status);

  return status;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_extended_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};
  int8_t status = div_conditions(value_1, value_2, result);

  if (status == 1) {
    MATH_OPERATIONS(DIV);
  }
  result->bytes[SIGN] = value_1.bytes[SIGN] ^ value_2.bytes[SIGN];
  set_status(big_result, result, &status);

  return status;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_extended_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};
  int8_t status = mod_conditions(value_2);

  if (status == 0) {
    MATH_OPERATIONS(MOD);
  }
  result->bytes[SIGN] = value_1.bytes[SIGN];
  set_status(big_result, result, &status);

  return status;
}
