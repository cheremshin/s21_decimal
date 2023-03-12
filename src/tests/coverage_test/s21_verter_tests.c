#include "s21_tests.h"


START_TEST(test_floor) {
  s21_decimal test_value_1 = {.bits = {1, 2, 3, 917504}};  
  s21_decimal test_value_2 = {.bits = {1, 2, 3, -2146566144}};
  s21_decimal test_value_3 = {.bits = {33, 2, 3000, -2146107392}};

  s21_decimal original_1 = {0};
  s21_decimal original_2 = {0};
  s21_decimal original_3 = {0};
  
  
  original_1.bits[0] = 0b10000111000110111010;

  original_2.bits[0] = 0b10000111000110111011;
  original_2.bytes[SIGN] = NEGATIVE;

  original_3.bits[0] = 0b111000;
  original_3.bytes[SIGN] = NEGATIVE;


  ck_assert_int_eq(0, s21_floor(test_value_1, &test_value_1));
  ck_assert_int_eq(0, s21_floor(test_value_2, &test_value_2));
  ck_assert_int_eq(0, s21_floor(test_value_3, &test_value_3));

  ck_assert_int_eq(1, s21_is_equal(test_value_1, original_1));
  ck_assert_int_eq(1, s21_is_equal(test_value_2, original_2));
  ck_assert_int_eq(1, s21_is_equal(test_value_2, original_2));
}
END_TEST


START_TEST(test_round) {
      s21_decimal test_value_1 = {.bits = {1, 2, 3, 917504}};
      s21_decimal test_value_2 = {.bits = {10, 100, 3, 1376256}};
      s21_decimal test_value_3 = {.bits = {16, 100, 3, 851968}};

      s21_round(test_value_1, &test_value_1);
      s21_round(test_value_2, &test_value_2);
      s21_round(test_value_3, &test_value_3);
}
END_TEST


START_TEST(test_truncate) {
      s21_decimal test_value_1 = {.bits = {32444, 100, 343253, -2145976320}};
      s21_decimal test_value_2 = {.bits = {1, 1, 1, 917504}};
      s21_decimal test_value_3 = {.bits = {0, 0, 0, 851968}};

      s21_truncate(test_value_1, &test_value_1);
      s21_truncate(test_value_2, &test_value_2);
      s21_truncate(test_value_3, &test_value_3);
}
END_TEST


START_TEST(test_negate) {
      s21_decimal test_value_1 = {.bits = {32444, 100, 343253, -2145976320}};
      s21_decimal test_value_2 = {.bits = {1, 1, 1, 917504}};
      s21_decimal test_value_3 = {.bits = {0, 0, 0, 917504}};

      s21_negate(test_value_1, &test_value_1);
      s21_negate(test_value_2, &test_value_2);
      s21_negate(test_value_3, &test_value_3);
}
END_TEST






START_TEST(test_add_1) {
      s21_decimal test_value1_1 = {.bits = {1, 1, 1, 65536}};                                    
      s21_decimal test_value2_1 = {.bits = {1, 1, 1, 65536}};
      s21_decimal result = {0};

      s21_add(test_value1_1, test_value2_1, &result);
}
END_TEST

START_TEST(test_add_2) {
      s21_decimal test_value1_2 = {.bits = {1, 1, 1, 65536}};
      s21_decimal test_value2_2 = {.bits = {1, 1, 1, 655360}};
      s21_decimal result = {0};

      s21_add(test_value1_2, test_value2_2, &result);
}
END_TEST

START_TEST(test_add_3) {
      s21_decimal test_value1_3 = {.bits = {24, 1, 1, -2147418112}};
      s21_decimal test_value2_3 = {.bits = {1, 15, 1, 655360}};
      s21_decimal result = {0};

      s21_add(test_value1_3, test_value2_3, &result);
}
END_TEST

START_TEST(test_add_4) {
      s21_decimal test_value1_4 = {.bits = {1, 1, 1, 655360}};
      s21_decimal test_value2_4 = {.bits = {1, 1, 1, -2147418112}};
      s21_decimal result = {0};

      s21_add(test_value1_4, test_value2_4, &result);
}
END_TEST







START_TEST(test_sub_1) {
      s21_decimal test_value1_1 = {.bits = {1, 1, 1, 65536}};
      s21_decimal test_value2_1 = {.bits = {1, 1, 1, -2147418112}};
      s21_decimal result = {0};

      s21_sub(test_value1_1, test_value2_1, &result);
}
END_TEST

START_TEST(test_sub_2) {
      s21_decimal test_value1_2 = {.bits = {1, 1, 1, -2147418112}};
      s21_decimal test_value2_2 = {.bits = {1, 1, 1, -2147418112}};
      s21_decimal result = {0};

      s21_sub(test_value1_2, test_value2_2, &result);
}
END_TEST

START_TEST(test_sub_3) {
      s21_decimal test_value1_3 = {.bits = {1, 1, 1, -2147418112}};
      s21_decimal test_value2_3 = {.bits = {1, 1, 1, 65536}};
      s21_decimal result = {0};

      s21_sub(test_value1_3, test_value2_3, &result);
}
END_TEST







START_TEST(test_mul_1) {
      s21_decimal test_value1_1 = {.bits = {1, 1, 1, 655360}};
      s21_decimal test_value2_1 = {.bits = {1, 1, 1, 655360}};
      s21_decimal result = {0};

      s21_mul(test_value1_1, test_value2_1, &result);
}
END_TEST

START_TEST(test_mul_2) {
      s21_decimal test_value1_2 = {.bits = {1, 0, 0, 655360}};
      s21_decimal test_value2_2 = {.bits = {1, 0, 0, 655360}};
      s21_decimal result = {0};

      s21_mul(test_value1_2, test_value2_2, &result);
}
END_TEST

START_TEST(test_mul_3) {
      s21_decimal test_value1_3 = {.bits = {1, 0, 0, 655360}};
      s21_decimal test_value2_3 = {.bits = {1, 0, 0, -2146828288}};
      s21_decimal result = {0};

      s21_mul(test_value1_3, test_value2_3, &result);
}
END_TEST

START_TEST(test_mul_4) {
      s21_decimal test_value1_4 = {.bits = {1, 0, 1, 917504}};
      s21_decimal test_value2_4 = {.bits = {1, 0, 0, -2146828288}};
      s21_decimal result = {0};

      s21_mul(test_value1_4, test_value2_4, &result);
}
END_TEST






START_TEST(test_div_1) {
      s21_decimal test_value1_1 = {.bits = {1, 1, 1, 655360}};
      s21_decimal test_value2_1 = {.bits = {1, 1, 1, 655360}};
      s21_decimal result = {0};

      s21_div(test_value1_1, test_value2_1, &result);
}
END_TEST

START_TEST(test_div_2) {
      s21_decimal test_value1_2 = {.bits = {1, 1, 1, 655360}};
      s21_decimal test_value2_2 = {.bits = {1, 1, 1, 983040}};
      s21_decimal result = {0};

      s21_div(test_value1_2, test_value2_2, &result);
}
END_TEST

START_TEST(test_div_3) {
      s21_decimal test_value1_3 = {.bits = {1, 1, 1, 655360}};
      s21_decimal test_value2_3 = {.bits = {1, 10, 1, -2146500608}};
      s21_decimal result = {0};

      s21_div(test_value1_3, test_value2_3, &result);
}
END_TEST

START_TEST(test_div_4) {
      s21_decimal test_value1_4 = {.bits = {1, 1, 1, 983040}};
      s21_decimal test_value2_4 = {.bits = {1, 1, 1, -2146500608}};
      s21_decimal result = {0};

      s21_div(test_value1_4, test_value2_4, &result);
}
END_TEST






START_TEST(test_mod_1) {
      s21_decimal test_value1_1 = {.bits = {1, 1, 1, 65536}};
      s21_decimal test_value2_1 = {.bits = {1, 1, 1, -2147418112}};
      s21_decimal result = {0};

      s21_mod(test_value1_1, test_value2_1, &result);
}
END_TEST

START_TEST(test_mod_2) {
      s21_decimal test_value1_2 = {.bits = {1, 1, 1, -2147418112}};
      s21_decimal test_value2_2 = {.bits = {1, 1, 1, -2146828288}};
      s21_decimal result = {0};

      s21_mod(test_value1_2, test_value2_2, &result);
}
END_TEST

START_TEST(test_mod_3) {
      s21_decimal test_value1_3 = {.bits = {1, 2, 3, -2147418112}};
      s21_decimal test_value2_3 = {.bits = {3, 2, 1, -2146828288}};
      s21_decimal result = {0};

      s21_mod(test_value1_3, test_value2_3, &result);
}
END_TEST

START_TEST(test_mod_4) {
      s21_decimal test_value1_4 = {.bits = {1, 2, 3, 655360}};
      s21_decimal test_value2_4 = {.bits = {3, 2, 1, -2146828288}};
      s21_decimal result = {0};

      s21_mod(test_value1_4, test_value2_4, &result);
}
END_TEST






START_TEST(test_is_less_1) {
      s21_decimal test_value1_1 = {.bits = {1, 2, 3, 655360}};
      s21_decimal test_value2_1 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_less(test_value1_1, test_value2_1);
}
END_TEST

START_TEST(test_is_less_2) {
      s21_decimal test_value1_2 = {.bits = {1, 2, 3, -2146828288}};
      s21_decimal test_value2_2 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_less(test_value1_2, test_value2_2);
}
END_TEST

START_TEST(test_is_less_3) {
      s21_decimal test_value1_3 = {.bits = {1, 2, 3, -2146566144}};
      s21_decimal test_value2_3 = {.bits = {3, 2, 1, -2146959360}};

      s21_is_less(test_value1_3, test_value2_3);
}
END_TEST

START_TEST(test_is_less_4) {
      s21_decimal test_value1_4 = {.bits = {10, 2, 3, -2146566144}};
      s21_decimal test_value2_4 = {.bits = {3, 2, 1, 524288}};

      s21_is_less(test_value1_4, test_value2_4);
}
END_TEST

START_TEST(test_is_less_5) {
      s21_decimal test_value1_5 = {.bits = {1, 2, 3, 917504}};
      s21_decimal test_value2_5 = {.bits = {1, 2, 3, 917504}};

      s21_is_less(test_value1_5, test_value2_5);
}
END_TEST











START_TEST(test_is_less_or_equal_1) {
      s21_decimal test_value1_1 = {.bits = {1, 2, 3, 655360}};
      s21_decimal test_value2_1 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_less_or_equal(test_value1_1, test_value2_1);
}
END_TEST

START_TEST(test_is_less_or_equal_2) {
      s21_decimal test_value1_2 = {.bits = {1, 2, 3, -2146828288}};
      s21_decimal test_value2_2 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_less_or_equal(test_value1_2, test_value2_2);
}
END_TEST

START_TEST(test_is_less_or_equal_3) {
      s21_decimal test_value1_3 = {.bits = {1, 2, 3, -2146566144}};
      s21_decimal test_value2_3 = {.bits = {3, 2, 1, -2146959360}};

      s21_is_less_or_equal(test_value1_3, test_value2_3);
}
END_TEST

START_TEST(test_is_less_or_equal_4) {
      s21_decimal test_value1_4 = {.bits = {10, 2, 3, -2146566144}};
      s21_decimal test_value2_4 = {.bits = {3, 2, 1, 524288}};

      s21_is_less_or_equal(test_value1_4, test_value2_4);
}
END_TEST

START_TEST(test_is_less_or_equal_5) {
      s21_decimal test_value1_5 = {.bits = {1, 2, 3, 917504}};
      s21_decimal test_value2_5 = {.bits = {1, 2, 3, 917504}};

      s21_is_less_or_equal(test_value1_5, test_value2_5);
}
END_TEST







START_TEST(test_is_greater_1) {
      s21_decimal test_value1_1 = {.bits = {1, 2, 3, 655360}};
      s21_decimal test_value2_1 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_greater(test_value1_1, test_value2_1);
}
END_TEST

START_TEST(test_is_greater_2) {
      s21_decimal test_value1_2 = {.bits = {1, 2, 3, -2146828288}};
      s21_decimal test_value2_2 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_greater(test_value1_2, test_value2_2);
}
END_TEST

START_TEST(test_is_greater_3) {
      s21_decimal test_value1_3 = {.bits = {1, 2, 3, -2146566144}};
      s21_decimal test_value2_3 = {.bits = {3, 2, 1, -2146959360}};

      s21_is_greater(test_value1_3, test_value2_3);
}
END_TEST

START_TEST(test_is_greater_4) {
      s21_decimal test_value1_4 = {.bits = {10, 2, 3, -2146566144}};
      s21_decimal test_value2_4 = {.bits = {3, 2, 1, 524288}};

      s21_is_greater(test_value1_4, test_value2_4);
}
END_TEST

START_TEST(test_is_greater_5) {
      s21_decimal test_value1_5 = {.bits = {1, 2, 3, 917504}};
      s21_decimal test_value2_5 = {.bits = {1, 2, 3, 917504}};

      s21_is_greater(test_value1_5, test_value2_5);
}
END_TEST










START_TEST(test_is_greater_or_equal_1) {
      s21_decimal test_value1_1 = {.bits = {1, 2, 3, 655360}};
      s21_decimal test_value2_1 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_greater_or_equal(test_value1_1, test_value2_1);
}
END_TEST

START_TEST(test_is_greater_or_equal_2) {
      s21_decimal test_value1_2 = {.bits = {1, 2, 3, -2146828288}};
      s21_decimal test_value2_2 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_greater_or_equal(test_value1_2, test_value2_2);
}
END_TEST

START_TEST(test_is_greater_or_equal_3) {
      s21_decimal test_value1_3 = {.bits = {1, 2, 3, -2146566144}};
      s21_decimal test_value2_3 = {.bits = {3, 2, 1, -2146959360}};

      s21_is_greater_or_equal(test_value1_3, test_value2_3);
}
END_TEST

START_TEST(test_is_greater_or_equal_4) {
      s21_decimal test_value1_4 = {.bits = {10, 2, 3, -2146566144}};
      s21_decimal test_value2_4 = {.bits = {3, 2, 1, 524288}};

      s21_is_greater_or_equal(test_value1_4, test_value2_4);
}
END_TEST

START_TEST(test_is_greater_or_equal_5) {
      s21_decimal test_value1_5 = {.bits = {1, 2, 3, 917504}};
      s21_decimal test_value2_5 = {.bits = {1, 2, 3, 917504}};

      s21_is_greater_or_equal(test_value1_5, test_value2_5);
}
END_TEST








START_TEST(test_is_equal_1) {
      s21_decimal test_value1_1 = {.bits = {1, 2, 3, 655360}};
      s21_decimal test_value2_1 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_equal(test_value1_1, test_value2_1);
}
END_TEST

START_TEST(test_is_equal_2) {
      s21_decimal test_value1_2 = {.bits = {1, 2, 3, -2146828288}};
      s21_decimal test_value2_2 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_equal(test_value1_2, test_value2_2);
}
END_TEST

START_TEST(test_is_equal_3) {
      s21_decimal test_value1_3 = {.bits = {1, 2, 3, -2146566144}};
      s21_decimal test_value2_3 = {.bits = {3, 2, 1, -2146959360}};

      s21_is_equal(test_value1_3, test_value2_3);
}
END_TEST

START_TEST(test_is_equal_4) {
      s21_decimal test_value1_4 = {.bits = {10, 2, 3, -2146566144}};
      s21_decimal test_value2_4 = {.bits = {3, 2, 1, 524288}};

      s21_is_equal(test_value1_4, test_value2_4);
}
END_TEST

START_TEST(test_is_equal_5) {
      s21_decimal test_value1_5 = {.bits = {1, 2, 3, 917504}};
      s21_decimal test_value2_5 = {.bits = {1, 2, 3, 917504}};

      s21_is_greater_or_equal(test_value1_5, test_value2_5);
}
END_TEST









START_TEST(test_is_not_equal_1) {
      s21_decimal test_value1_1 = {.bits = {1, 2, 3, 655360}};
      s21_decimal test_value2_1 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_not_equal(test_value1_1, test_value2_1);
}
END_TEST

START_TEST(test_is_not_equal_2) {
      s21_decimal test_value1_2 = {.bits = {1, 2, 3, -2146828288}};
      s21_decimal test_value2_2 = {.bits = {3, 2, 1, -2146828288}};

      s21_is_not_equal(test_value1_2, test_value2_2);
}
END_TEST

START_TEST(test_is_not_equal_3) {
      s21_decimal test_value1_3 = {.bits = {1, 2, 3, -2146566144}};
      s21_decimal test_value2_3 = {.bits = {3, 2, 1, -2146959360}};

      s21_is_not_equal(test_value1_3, test_value2_3);
}
END_TEST

START_TEST(test_is_not_equal_4) {
      s21_decimal test_value1_4 = {.bits = {10, 2, 3, -2146566144}};
      s21_decimal test_value2_4 = {.bits = {3, 2, 1, 524288}};

      s21_is_not_equal(test_value1_4, test_value2_4);
}
END_TEST

START_TEST(test_is_not_equal_5) {
      s21_decimal test_value1_5 = {.bits = {1, 2, 3, 917504}};
      s21_decimal test_value2_5 = {.bits = {1, 2, 3, 917504}};

      s21_is_greater_or_equal(test_value1_5, test_value2_5);
}
END_TEST








START_TEST(test_from_decimal_to_int_1) {
      s21_decimal test_value_1 = {.bits = {10, 0, 0, 0}};
      int32_t test_value_2 = 0;

      s21_from_decimal_to_int(test_value_1, &test_value_2);
}
END_TEST


START_TEST(test_from_decimal_to_int_2) {
      s21_decimal test_value_1 = {.bits = {133456435, 0, 0, -2147483648}};
      int32_t test_value_2 = 0;

      s21_from_decimal_to_int(test_value_1, &test_value_2);
}
END_TEST


START_TEST(test_from_decimal_to_float_1) {
      s21_decimal test_value_1 = {.bits = {2343453, 0, 0, -2147024896}};
      float test_value_2 = 0;

      s21_from_decimal_to_float(test_value_1, &test_value_2);
}
END_TEST


START_TEST(test_from_decimal_to_float_2) {
      s21_decimal test_value_1 = {.bits = {1272343, 0, 0, 262144}};
      float test_value_2 = 0;

      s21_from_decimal_to_float(test_value_1, &test_value_2);
}
END_TEST




Suite *verter_tests(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("verter_tests");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_floor);
  tcase_add_test(tc, test_round);
  tcase_add_test(tc, test_truncate);
  tcase_add_test(tc, test_negate);
 


  tcase_add_test(tc, test_add_1);
  tcase_add_test(tc, test_add_2);
  tcase_add_test(tc, test_add_3);
  tcase_add_test(tc, test_add_4);

  tcase_add_test(tc, test_sub_1);
  tcase_add_test(tc, test_sub_2);
  tcase_add_test(tc, test_sub_3);

  tcase_add_test(tc, test_mul_1);
  tcase_add_test(tc, test_mul_2);
  tcase_add_test(tc, test_mul_3);
  tcase_add_test(tc, test_mul_4);

  tcase_add_test(tc, test_div_1);
  tcase_add_test(tc, test_div_2);
  tcase_add_test(tc, test_div_3);
  tcase_add_test(tc, test_div_4);



  tcase_add_test(tc, test_is_less_1);
  tcase_add_test(tc, test_is_less_2);
  tcase_add_test(tc, test_is_less_3);
  tcase_add_test(tc, test_is_less_4);
  tcase_add_test(tc, test_is_less_5);

  tcase_add_test(tc, test_is_less_or_equal_1);
  tcase_add_test(tc, test_is_less_or_equal_2);
  tcase_add_test(tc, test_is_less_or_equal_3);
  tcase_add_test(tc, test_is_less_or_equal_4);
  tcase_add_test(tc, test_is_less_or_equal_5);

  tcase_add_test(tc, test_is_greater_1);
  tcase_add_test(tc, test_is_greater_2);
  tcase_add_test(tc, test_is_greater_3);
  tcase_add_test(tc, test_is_greater_4);
  tcase_add_test(tc, test_is_greater_5);

  tcase_add_test(tc, test_is_greater_or_equal_1);
  tcase_add_test(tc, test_is_greater_or_equal_2);
  tcase_add_test(tc, test_is_greater_or_equal_3);
  tcase_add_test(tc, test_is_greater_or_equal_4);
  tcase_add_test(tc, test_is_greater_or_equal_5);

  tcase_add_test(tc, test_is_equal_1);
  tcase_add_test(tc, test_is_equal_2);
  tcase_add_test(tc, test_is_equal_3);
  tcase_add_test(tc, test_is_equal_4);
  tcase_add_test(tc, test_is_equal_5);

  tcase_add_test(tc, test_is_not_equal_1);
  tcase_add_test(tc, test_is_not_equal_2);
  tcase_add_test(tc, test_is_not_equal_3);
  tcase_add_test(tc, test_is_not_equal_4);
  tcase_add_test(tc, test_is_not_equal_5);


  tcase_add_test(tc, test_from_decimal_to_int_1);
  tcase_add_test(tc, test_from_decimal_to_int_2);
  tcase_add_test(tc, test_from_decimal_to_float_1);
  tcase_add_test(tc, test_from_decimal_to_float_2);

  return s;
}