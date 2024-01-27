#include "test.h"

START_TEST(test_sqrt_positive_int) {
  ck_assert_ldouble_eq_tol(s21_sqrt(23), sqrt(23), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(625), sqrt(625), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(3294), sqrt(3294), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(160), sqrt(160), S21_EPSILON);
}
END_TEST

START_TEST(test_sqrt_negative_int) {
  ck_assert(isnan(s21_sqrt(-1)) == 1);
  ck_assert(isnan(s21_sqrt(-64)) == 1);
  ck_assert(isnan(s21_sqrt(-23749)) == 1);
  ck_assert(isnan(s21_sqrt(-52)) == 1);
  ck_assert(isnan(s21_sqrt(-778)) == 1);
}
END_TEST

START_TEST(test_sqrt_positive_double) {
  ck_assert_ldouble_eq_tol(s21_sqrt(4.234), sqrt(4.234), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.5), sqrt(0.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.9999), sqrt(0.9999), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(1 - 0.999999 * 0.999999),
                           sqrt(1 - 0.999999 * 0.999999), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(234.272365), sqrt(234.272365), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(65.389), sqrt(65.389), S21_EPSILON);
}
END_TEST

START_TEST(test_sqrt_negative_double) {
  ck_assert(isnan(s21_sqrt(-5.745)) == 1);
  ck_assert(isnan(s21_sqrt(-0.6)) == 1);
  ck_assert(isnan(s21_sqrt(-0.11111)) == 1);
  ck_assert(isnan(s21_sqrt(-3452.234)) == 1);
  ck_assert(isnan(s21_sqrt(-74.629)) == 1);
}
END_TEST

START_TEST(test_sqrt_specific_value) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(+0.0), sqrt(+0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(-0.0), sqrt(-0.0), S21_EPSILON);
  ck_assert(isnan(s21_sqrt(S21_NAN)) == 1);
  ck_assert_ldouble_eq(s21_sqrt(S21_INFINITY), sqrt(S21_INFINITY));
  ck_assert(isnan(s21_sqrt(S21_N_INFINITY)) == 1);
}
END_TEST

Suite *test_s21_sqrt(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_sqrt]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_sqrt");

  tcase_add_test(tc, test_sqrt_positive_int);
  tcase_add_test(tc, test_sqrt_negative_int);
  tcase_add_test(tc, test_sqrt_positive_double);
  tcase_add_test(tc, test_sqrt_negative_double);
  tcase_add_test(tc, test_sqrt_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
