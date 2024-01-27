#include "test.h"

START_TEST(test_abs_positive_int) {
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(17), abs(17));
  ck_assert_int_eq(s21_abs(26), abs(26));
  ck_assert_int_eq(s21_abs(50), abs(50));
  ck_assert_int_eq(s21_abs(96), abs(96));
}
END_TEST

START_TEST(test_abs_negative_int) {
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(-17), abs(-17));
  ck_assert_int_eq(s21_abs(-26), abs(-26));
  ck_assert_int_eq(s21_abs(-50), abs(-50));
  ck_assert_int_eq(s21_abs(-96), abs(-96));
}
END_TEST

START_TEST(test_abs_specific_value) {
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
}
END_TEST

Suite *test_s21_abs(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_abs]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_abs");

  tcase_add_test(tc, test_abs_positive_int);
  tcase_add_test(tc, test_abs_negative_int);
  tcase_add_test(tc, test_abs_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
