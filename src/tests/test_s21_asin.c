#include "test.h"

START_TEST(test_asin_positive_double) {
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(0.25), asin(0.25), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(0.111), asin(0.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(0.15), asin(0.15), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(0.255), asin(0.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(0.25556), asin(0.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(0.000125), asin(0.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(0.999999), asin(0.999999), S21_EPSILON);
}
END_TEST

START_TEST(test_asin_negative_double) {
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.25), asin(-0.25), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.111), asin(-0.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.15), asin(-0.15), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.255), asin(-0.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.25556), asin(-0.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.000125), asin(-0.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.999999), asin(-0.999999), S21_EPSILON);
}
END_TEST

START_TEST(test_asin_specific_value) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.0), asin(-0.0), S21_EPSILON);
  ck_assert(isnan(s21_asin(INFINITY)) == 1);
  ck_assert(isnan(s21_asin(-INFINITY)) == 1);
  ck_assert(isnan(s21_asin(S21_INFINITY)) == 1);
  ck_assert(isnan(s21_asin(S21_N_INFINITY)) == 1);
}
END_TEST

START_TEST(test_asin_nan) {
  ck_assert(isnan(s21_asin(10)) == 1);
  ck_assert(isnan(s21_asin(100)) == 1);
  ck_assert(isnan(s21_asin(1000)) == 1);
  ck_assert(isnan(s21_asin(10000)) == 1);
  ck_assert(isnan(s21_asin(100000)) == 1);
  ck_assert(isnan(s21_asin(1000000)) == 1);
  ck_assert(isnan(s21_asin(9999999)) == 1);
  ck_assert(isnan(s21_asin(100.25)) == 1);
  ck_assert(isnan(s21_asin(100.111111)) == 1);
  ck_assert(isnan(s21_asin(9999999.99999)) == 1);
  ck_assert(isnan(s21_asin(-10)) == 1);
  ck_assert(isnan(s21_asin(-100)) == 1);
  ck_assert(isnan(s21_asin(-1000)) == 1);
  ck_assert(isnan(s21_asin(-10000)) == 1);
  ck_assert(isnan(s21_asin(-1000.0)) == 1);
  ck_assert(isnan(s21_asin(-1000.000000)) == 1);
  ck_assert(isnan(s21_asin(-100000)) == 1);
  ck_assert(isnan(s21_asin(-1000000)) == 1);
  ck_assert(isnan(s21_asin(-9999999)) == 1);
  ck_assert(isnan(s21_asin(-100.25)) == 1);
  ck_assert(isnan(s21_asin(-100.111111)) == 1);
  ck_assert(isnan(s21_asin(-9999999.99999)) == 1);
  ck_assert(isnan(s21_asin(S21_NAN)) == 1);
}
END_TEST

Suite *test_s21_asin(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_asin]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_asin");

  tcase_add_test(tc, test_asin_positive_double);
  tcase_add_test(tc, test_asin_negative_double);
  tcase_add_test(tc, test_asin_specific_value);
  tcase_add_test(tc, test_asin_nan);

  suite_add_tcase(s, tc);
  return s;
}
