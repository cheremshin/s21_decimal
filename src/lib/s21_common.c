#include "extended_decimal.h"

int s21_is_zero(s21_decimal num) {
  return (!num.bits[0] && !num.bits[1] && !num.bits[2]);
}

void copy_decimal(s21_decimal value, s21_decimal *result) {
  for (size_t i = 0; i < 4; i++) {
    result->bits[i] = value.bits[i];
  }
}

void set_default(s21_decimal *src) {
  for (size_t i = 0; i < 16; i++) {
    src->bytes[i] = 0;
  }
}

void write_normalized(s21_decimal *dst, int number, int exponent) {
  union {
    int copy;
    uint8_t copy_bytes[4];
  } int_union = {number};

  for (size_t i = 0; i < 4; i++) {
    dst->bytes[i] = int_union.copy_bytes[i];
  }

  dst->bytes[EXP] = exponent;
}

int get_number_of_digits(int value) {
  return (value == 0) ? 1 : log10(value) + 1;
}

