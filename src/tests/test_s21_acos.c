#include "test.h"

START_TEST(test_acos_positive_double) {
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(0.25), acos(0.25), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(0.111), acos(0.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(0.15), acos(0.15), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(0.255), acos(0.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(0.25556), acos(0.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(0.000125), acos(0.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(0.999999), acos(0.999999), S21_EPSILON);
}
END_TEST

START_TEST(test_acos_negative_double) {
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.25), acos(-0.25), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.111), acos(-0.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.15), acos(-0.15), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.255), acos(-0.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.25556), acos(-0.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.000125), acos(-0.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.999999), acos(-0.999999), S21_EPSILON);
}
END_TEST

START_TEST(test_acos_specific_value) {
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), S21_EPSILON);
  ck_assert(isnan(s21_acos(INFINITY)) == 1);
  ck_assert(isnan(s21_acos(-INFINITY)) == 1);
  ck_assert(isnan(s21_acos(S21_INFINITY)) == 1);
  ck_assert(isnan(s21_acos(S21_N_INFINITY)) == 1);
}
END_TEST

START_TEST(test_acos_nan) {
  ck_assert(isnan(s21_acos(10)) == 1);
  ck_assert(isnan(s21_acos(100)) == 1);
  ck_assert(isnan(s21_acos(1000)) == 1);
  ck_assert(isnan(s21_acos(10000)) == 1);
  ck_assert(isnan(s21_acos(100000)) == 1);
  ck_assert(isnan(s21_acos(1000000)) == 1);
  ck_assert(isnan(s21_acos(9999999)) == 1);
  ck_assert(isnan(s21_acos(100.25)) == 1);
  ck_assert(isnan(s21_acos(100.111111)) == 1);
  ck_assert(isnan(s21_acos(9999999.99999)) == 1);
  ck_assert(isnan(s21_acos(-10)) == 1);
  ck_assert(isnan(s21_acos(-100)) == 1);
  ck_assert(isnan(s21_acos(-1000)) == 1);
  ck_assert(isnan(s21_acos(-10000)) == 1);
  ck_assert(isnan(s21_acos(-1000.0)) == 1);
  ck_assert(isnan(s21_acos(-1000.000000)) == 1);
  ck_assert(isnan(s21_acos(-100000)) == 1);
  ck_assert(isnan(s21_acos(-1000000)) == 1);
  ck_assert(isnan(s21_acos(-9999999)) == 1);
  ck_assert(isnan(s21_acos(-100.25)) == 1);
  ck_assert(isnan(s21_acos(-100.111111)) == 1);
  ck_assert(isnan(s21_acos(-9999999.99999)) == 1);
}
END_TEST

Suite *test_s21_acos() {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_acos]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_acos");

  tcase_add_test(tc, test_acos_positive_double);
  tcase_add_test(tc, test_acos_negative_double);
  tcase_add_test(tc, test_acos_specific_value);
  tcase_add_test(tc, test_acos_nan);

  suite_add_tcase(s, tc);
  return s;
}
