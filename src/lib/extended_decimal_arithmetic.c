#include "extended_decimal.h"

void sum_extended_decimal(s21_extended_decimal value_1, s21_extended_decimal value_2,
                     s21_extended_decimal* result) {
  mantissa_set_default(result);
  uint64_t transfer_bit = 0;

  for (int i = 0; i < 6; i++) {
    transfer_bit += (uint64_t)value_1.bits[i] + value_2.bits[i];
    result->bits[i] = transfer_bit;
    transfer_bit >>= 32;
  }
}

void sub_extended_decimal(s21_extended_decimal value_1, s21_extended_decimal value_2,
                     s21_extended_decimal* result) {
  mantissa_set_default(result);

  inverse_extended_decimal(&value_1);

  sum_extended_decimal(value_1, value_2, result);

  inverse_extended_decimal(result);
}

void mul_extended_decimal(s21_extended_decimal value_1, s21_extended_decimal value_2,
                     s21_extended_decimal* result) {
  mantissa_set_default(result);

  uint8_t start_bit_2 = get_start_bit_extended_decimal(value_2);
  uint8_t num_current_bit_2 = 0;

  for (int i = 0; i < 6 && num_current_bit_2 <= start_bit_2; i++) {
    for (int j = 0; j < 32 && num_current_bit_2 <= start_bit_2; j++) {
      uint32_t current_bit_value_2 = (value_2.bits[i] >> j) & 1;

      if (current_bit_value_2) {
        sum_extended_decimal(value_1, *result, result);
      }
      left_offset_extended_decimal(&value_1, 1);
      num_current_bit_2++;
    }
  }
  result->bytes[BIG_EXP] = result->bytes[BIG_EXP] + result->bytes[BIG_EXP];
}

void div_extended_decimal(s21_extended_decimal value_1, s21_extended_decimal value_2,
                     s21_extended_decimal* result) {
  mantissa_set_default(result);
  cast_to_one_exp(&value_1, &value_2);

  if (mantissa_comparison_extended_decimal(value_1, value_2) == 0) {
    result->bytes[0] = 1;
  } else {
    while (mantissa_comparison_extended_decimal(value_1, value_2) == 1) {
      mul10_extended_decimal(&value_1);
      result->bytes[BIG_EXP]++;
    }

    division(&value_1, value_2, result);

    while (extended_decimal_is_zero(value_1) == 0 &&
           get_start_bit_extended_decimal(*result) < 112) {
      s21_extended_decimal tmp_res = {0};

      mul10_extended_decimal(&value_1);
      division(&value_1, value_2, &tmp_res);

      mul10_extended_decimal(result);
      sum_extended_decimal(*result, tmp_res, result);
    }
  }
}

void mod_extended_decimal(s21_extended_decimal value_1, s21_extended_decimal value_2,
                     s21_extended_decimal* result) {
  mantissa_set_default(result);
  division(&value_1, value_2, result);
  copy_extended_decimal(value_1, result);
}