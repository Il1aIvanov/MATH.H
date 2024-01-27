#include "test.h"

START_TEST(test_ceil_positive_double) {
  ck_assert_ldouble_eq_tol(s21_ceil(1), ceil(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(0.5), ceil(0.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(0.25), ceil(0.25), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(0.111), ceil(0.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(0.15), ceil(0.15), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(0.255), ceil(0.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(0.25556), ceil(0.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(0.000125), ceil(0.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(0.999999), ceil(0.999999), S21_EPSILON);
}
END_TEST

START_TEST(test_ceil_negative_double) {
  ck_assert_ldouble_eq_tol(s21_ceil(-1), ceil(-1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.5), ceil(-0.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.25), ceil(-0.25), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.111), ceil(-0.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.15), ceil(-0.15), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.255), ceil(-0.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.25556), ceil(-0.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.000125), ceil(-0.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.999999), ceil(-0.999999), S21_EPSILON);
}
END_TEST

START_TEST(test_ceil_specific_value) {
  ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceil(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.0), ceil(-0.0), S21_EPSILON);
  ck_assert_ldouble_eq(s21_ceil(S21_INFINITY), ceil(S21_INFINITY));
  ck_assert_ldouble_eq(s21_ceil(S21_N_INFINITY), ceil(S21_N_INFINITY));
  ck_assert(isnan(s21_ceil(S21_NAN)) == 1);
}
END_TEST

START_TEST(test_ceil_big_value) {
  ck_assert_ldouble_eq_tol(s21_ceil(10000), ceil(10000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(123456789.123), ceil(123456789.123),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(999999999999999.01),
                           ceil(999999999999999.01), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(54321.111), ceil(54321.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(8888880.15), ceil(8888880.15), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(99999999.00000001), ceil(99999999.00000001),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-10000), ceil(-10000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-123456789.123), ceil(-123456789.123),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-999999999999999.01),
                           ceil(-999999999999999.01), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-54321.111), ceil(-54321.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-8888880.15), ceil(-8888880.15),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-99999999.00000001),
                           ceil(-99999999.00000001), S21_EPSILON);
}
END_TEST

Suite *test_s21_ceil(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_ceil]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_ceil");

  tcase_add_test(tc, test_ceil_positive_double);
  tcase_add_test(tc, test_ceil_negative_double);
  tcase_add_test(tc, test_ceil_big_value);
  tcase_add_test(tc, test_ceil_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
