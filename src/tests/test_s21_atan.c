#include "test.h"

START_TEST(test_atan_positive_double) {
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(0.25), atan(0.25), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(0.111), atan(0.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(0.15), atan(0.15), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(0.255), atan(0.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(0.25556), atan(0.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(0.000125), atan(0.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(0.999999), atan(0.999999), S21_EPSILON);
}
END_TEST

START_TEST(test_atan_negative_double) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-0.25), atan(-0.25), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-0.111), atan(-0.111), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-0.15), atan(-0.15), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-0.255), atan(-0.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-0.25556), atan(-0.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-0.000125), atan(-0.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-0.999999), atan(-0.999999), S21_EPSILON);
}
END_TEST

START_TEST(test_atan_big_value) {
  ck_assert_ldouble_eq_tol(s21_atan(1000), atan(1000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(10000), atan(10000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(50000), atan(50000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(60000), atan(60000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(10000000), atan(10000000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(1000.255), atan(1000.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(120.25556), atan(120.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(55.000125), atan(55.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(2.999999), atan(2.999999), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-1000), atan(-1000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-10000), atan(-10000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-50000), atan(-50000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-60000), atan(-60000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-10000000), atan(-10000000), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-1000.255), atan(-1000.255), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-120.25556), atan(-120.25556), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-55.000125), atan(-55.000125), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-2.999999), atan(-2.999999), S21_EPSILON);
}
END_TEST

START_TEST(test_atan_specific_value) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), atan(INFINITY), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-INFINITY), atan(-INFINITY), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(S21_INFINITY), atan(S21_INFINITY),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(S21_N_INFINITY), atan(S21_N_INFINITY),
                           S21_EPSILON);
}
END_TEST

Suite *test_s21_atan(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_atan]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_atan");

  tcase_add_test(tc, test_atan_positive_double);
  tcase_add_test(tc, test_atan_negative_double);
  tcase_add_test(tc, test_atan_big_value);
  tcase_add_test(tc, test_atan_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
