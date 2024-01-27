#include "test.h"

START_TEST(test_log_positive_int) {
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(18), log(18), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(63), log(63), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(184), log(184), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(25739), log(25739), S21_EPSILON);
}
END_TEST

START_TEST(test_log_negative_int) {
  ck_assert(isnan(s21_log(-1)) == 1);
  ck_assert(isnan(s21_log(-37)) == 1);
  ck_assert(isnan(s21_log(-255)) == 1);
  ck_assert(isnan(s21_log(-841)) == 1);
  ck_assert(isnan(s21_log(-18538)) == 1);
}
END_TEST

START_TEST(test_log_positive_double) {
  ck_assert_ldouble_eq_tol(s21_log(0.0000645), log(0.0000645), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(0.999), log(0.999), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(2.643), log(2.643), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(2.0), log(2.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(35.963745), log(35.963745), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(572.864), log(572.864), S21_EPSILON);
}
END_TEST

START_TEST(test_log_negative_double) {
  ck_assert(isnan(s21_log(-0.00000796345)) == 1);
  ck_assert(isnan(s21_log(-1.000234)) == 1);
  ck_assert(isnan(s21_log(-8.6423)) == 1);
  ck_assert(isnan(s21_log(-54.7854)) == 1);
  ck_assert(isnan(s21_log(-3478.9645)) == 1);
}
END_TEST

START_TEST(test_log_specific_value) {
  ck_assert_ldouble_eq(s21_log(0.0), log(0.0));
  ck_assert_ldouble_eq(s21_log(+0.0), log(+0.0));
  ck_assert_ldouble_eq(s21_log(-0.0), log(-0.0));
  ck_assert(isnan(s21_log(S21_NAN)) == 1);
  ck_assert_ldouble_eq(s21_log(S21_INFINITY), log(S21_INFINITY));
  ck_assert(isnan(s21_log(S21_N_INFINITY)) == 1);
}
END_TEST

Suite *test_s21_log(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_log]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_log");

  tcase_add_test(tc, test_log_positive_int);
  tcase_add_test(tc, test_log_negative_int);
  tcase_add_test(tc, test_log_positive_double);
  tcase_add_test(tc, test_log_negative_double);
  tcase_add_test(tc, test_log_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
