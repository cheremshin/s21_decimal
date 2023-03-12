#include "extended_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  set_default(dst);

  if (src < 0) {
    src *= -1;
    dst->bytes[SIGN] = NEGATIVE;
  }
  dst->bits[0] = src;

  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = 0;
  set_default(dst);

  if (src >= MAX_DECIMAL || src <= MIN_DECIMAL ||
      fabsf(src) < pow(10.0f, (float)-28.0) || src == INFINITY ||
      src == -INFINITY) {
    status = 1;
  } else {
    union {
      float copy;
      uint8_t copy_bytes[4];
    } float_union = {src};

    if (float_union.copy_bytes[3] & NEGATIVE) {
      dst->bytes[SIGN] = float_union.copy_bytes[3] & NEGATIVE;
      float_union.copy_bytes[3] ^= NEGATIVE;
    }

    int whole_part = (int)float_union.copy;
    int whole_part_size = get_number_of_digits(whole_part);
    float fract_part = float_union.copy - whole_part;

    long double decimal = (long double)whole_part;

    int scale = 0;
    // Normalize number to integer form
    while (((whole_part != 0 && fract_part != 0 &&
             scale <= FLOAT_DIGITS - whole_part_size) ||
            (get_number_of_digits((int)decimal) != 8)) &&
           scale != 29) {
      decimal = decimal * 10.0l + (int)(fract_part * 10.0f);
      fract_part *= 10.0f;
      fract_part -= (int)fract_part;
      scale++;
    }

    // Round number to 7 valuable digits
    if (whole_part_size > FLOAT_DIGITS) {
      whole_part %= whole_part_size - FLOAT_DIGITS;
      decimal = decimal + (roundl(decimal) - whole_part);
    } else if (fract_part != 0) {
      decimal = roundl(decimal / 10.0L);
      scale--;
    }

    write_normalized(dst, (int)decimal, scale);

    s21_extended_decimal extended_dst = {0};
    decimal_to_extended_decimal(*dst, &extended_dst);
    clear_trailing_zeros(&extended_dst);
    extended_decimal_to_decimal(extended_dst, dst);

  }

  return status;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status = 0;

  if (src.bytes[EXP] > 0) {
    s21_truncate(src, &src);
  }

  if (src.bits[1] || src.bits[2]) {
    status = 1;
  } else {
    *dst = src.bits[0];
    if (src.bytes[SIGN] == NEGATIVE) {
      *dst *= -1;
    }
  }

  return status;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = 0;
  long double result = 0.0l;

  // convert mantissa to integer value, stored in result variable
  for (size_t i = 0; i < 96; i++) {
    if (src.bytes[i / 8] & (1 << i % 8)) {
      result += powl(2.0l, (long double)i);
    }
  }

  // bring the number accordance to the exponent
  for (int exponent = src.bytes[EXP]; exponent > 0; exponent--) {
    result /= 10.0l;
  }

  *dst = (float)result;
  *dst *= src.bytes[SIGN] & NEGATIVE ? -1 : 1;

  return status;
}
