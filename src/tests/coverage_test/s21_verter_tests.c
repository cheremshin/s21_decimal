#include "s21_tests.h"


START_TEST(test_mul_1) {
    s21_decimal test_value1_1 = {.bits = {1, 1, 1, 655360}};
    s21_decimal test_value2_1 = {.bits = {1, 1, 1, 655360}};
    s21_decimal origin_result = {0};
    s21_decimal result = {0};

    origin_result.bits[0] = 0b01100010100000011111010111111101;
    origin_result.bits[1] = 0b00111010110111011110100110101111;
    origin_result.bits[2] = 0b1101101111100110111111101101000;
    origin_result.bytes[EXP] = 10;

    ck_assert_int_eq(0, s21_mul(test_value1_1, test_value2_1, &result));
    ck_assert_int_eq(1, s21_is_equal(origin_result, result));
}
END_TEST

START_TEST(test_mul_2) {
      s21_decimal test_value1_2 = {.bits = {1, 0, 0, 655360}};
      s21_decimal test_value2_2 = {.bits = {1, 0, 0, 655360}};
      s21_decimal original_result = {0};
      s21_decimal result = {0};

      original_result.bits[0] = 1;
      original_result.bytes[EXP] = 20;

      ck_assert_int_eq(0, s21_mul(test_value1_2, test_value2_2, &result));
      ck_assert_int_eq(1, s21_is_equal(original_result, result));
}
END_TEST

START_TEST(test_mul_3) {
      s21_decimal test_value1_3 = {.bits = {1, 0, 0, 655360}};
      s21_decimal test_value2_3 = {.bits = {1, 0, 0, -2146828288}};
      s21_decimal original_result = {0};
      s21_decimal result = {0};

      original_result.bits[0] = 1;
      original_result.bytes[EXP] = 20;
      original_result.bytes[SIGN] = NEGATIVE;

      ck_assert_int_eq(0, s21_mul(test_value1_3, test_value2_3, &result));
      ck_assert_int_eq(1, s21_is_equal(original_result, result));
}
END_TEST

START_TEST(test_mul_4) {
      s21_decimal test_value1_4 = {.bits = {1, 0, 1, 917504}};
      s21_decimal test_value2_4 = {.bits = {1, 0, 0, -2146828288}};
      s21_decimal original_result = {0};
      s21_decimal result = {0};

      original_result.bits[0] = 1;
      original_result.bits[1] = 0;
      original_result.bits[2] = 1;
      original_result.bytes[EXP] = 24;
      original_result.bytes[SIGN] = NEGATIVE;

      ck_assert_int_eq(0, s21_mul(test_value1_4, test_value2_4, &result));
      ck_assert_int_eq(1, s21_is_equal(original_result, result));
}
END_TEST


START_TEST(test_div_1) {
      s21_decimal test_value1_1 = {.bits = {1, 1, 1, 655360}};
      s21_decimal test_value2_1 = {.bits = {1, 1, 1, 655360}};
      s21_decimal original_result = {0};
      s21_decimal result = {0};

      original_result.bits[0] = 0b01100010100000011111010111111101;
      original_result.bits[1] = 0b00111010110111011110100110101111;
      original_result.bits[2] = 0b1101101111100110111111101101000;
      original_result.bytes[EXP] = 20;

      s21_div(test_value1_1, test_value2_1, &result);
}
END_TEST

START_TEST(test_div_2) {
      s21_decimal test_value1_2 = {.bits = {1, 1, 1, 655360}};
      s21_decimal test_value2_2 = {.bits = {1, 1, 1, 983040}};
      s21_decimal original_result = {0};
      s21_decimal result = {0};

      original_result.bits[0] = 0b01100010100000011111010111111101;
      original_result.bits[1] = 0b00111010110111011110100110101111;
      original_result.bits[2] = 0b1101101111100110111111101101000;
      original_result.bytes[EXP] = 25;

      s21_div(test_value1_2, test_value2_2, &result);
}
END_TEST

START_TEST(test_div_3) {
      s21_decimal test_value1_3 = {.bits = {1, 1, 1, 655360}};
      s21_decimal test_value2_3 = {.bits = {1, 10, 1, -2146500608}};
      s21_decimal original_result = {0};
      s21_decimal result = {0};

      original_result.bits[0] = 0b01100010100000011111010111111101;
      original_result.bits[1] = 0b00111010110111011110100110101111;
      original_result.bits[2] = 0b1101101111100110111111101101000;
      original_result.bytes[EXP] = 20;

      s21_div(test_value1_3, test_value2_3, &result);
}
END_TEST

START_TEST(test_div_4) {
      s21_decimal test_value1_4 = {.bits = {1, 1, 1, 983040}};
      s21_decimal test_value2_4 = {.bits = {1, 1, 1, -2146500608}};
      s21_decimal original_result = {0};
      s21_decimal result = {0};

      original_result.bits[0] = 0b01100010100000011111010111111101;
      original_result.bits[1] = 0b00111010110111011110100110101111;
      original_result.bits[2] = 0b1101101111100110111111101101000;
      original_result.bytes[EXP] = 30;

      s21_div(test_value1_4, test_value2_4, &result);
}
END_TEST


START_TEST(test_from_decimal_to_int_1) {
    s21_decimal test_value_1 = {.bits = {10, 0, 0, 0}};
    int32_t result = 0;
    int32_t original_result = 10;

    ck_assert_int_eq(0, s21_from_decimal_to_int(test_value_1, &result));
    ck_assert_int_eq(original_result, result);
}
END_TEST


START_TEST(test_from_decimal_to_int_2) {
      s21_decimal test_value_1 = {.bits = {133456435, 0, 0, -2147483648}};
      int32_t result = 0;
      int32_t original_result = -133456435;

      ck_assert_int_eq(0, s21_from_decimal_to_int(test_value_1, &result));
      ck_assert_int_eq(original_result, result);
}
END_TEST


START_TEST(test_from_decimal_to_float_1) {
      s21_decimal test_value_1 = {.bits = {2343453, 0, 0, -2147024896}};
      float result = 0;
      float original_result = -0.2343453;

      ck_assert_int_eq(0, s21_from_decimal_to_float(test_value_1, &result));
      ck_assert_float_eq_tol(original_result, result, 1e-6);
}
END_TEST


START_TEST(test_from_decimal_to_float_2) {
      s21_decimal test_value_1 = {.bits = {1272343, 0, 0, 262144}};
      float result = 0;
      float original_result = 127.2343;
      
      ck_assert_int_eq(0, s21_from_decimal_to_float(test_value_1, &result));
      ck_assert_float_eq_tol(original_result, result, 1e-6);
}
END_TEST


Suite *verter_tests(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("verter_tests");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_mul_1);
  tcase_add_test(tc, test_mul_2);
  tcase_add_test(tc, test_mul_3);
  tcase_add_test(tc, test_mul_4);

  tcase_add_test(tc, test_div_1);
  tcase_add_test(tc, test_div_2);
  tcase_add_test(tc, test_div_3);
  tcase_add_test(tc, test_div_4);

  tcase_add_test(tc, test_from_decimal_to_int_1);
  tcase_add_test(tc, test_from_decimal_to_int_2);
  tcase_add_test(tc, test_from_decimal_to_float_1);
  tcase_add_test(tc, test_from_decimal_to_float_2);

  return s;
}