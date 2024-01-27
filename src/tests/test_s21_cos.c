#include "test.h"

START_TEST(test_cos_positive_double) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cosl(S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI / 2), cosl(S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(3 * S21_PI / 2), cosl(3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(2 * S21_PI), cosl(2 * S21_PI), S21_EPSILON);
}
END_TEST

START_TEST(test_cos_negative_double) {
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI), cosl(-S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI / 2), cosl(-S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(-3 * S21_PI / 2), cosl(-3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(-2 * S21_PI), cosl(-2 * S21_PI),
                           S21_EPSILON);
}
END_TEST

START_TEST(test_cos_specific_value) {
  ck_assert_ldouble_eq_tol(s21_cos(0.0), cosl(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(-0.0), cosl(-0.0), S21_EPSILON);
  ck_assert(isnan(s21_cos(S21_NAN)) == 1);
  ck_assert(isnan(s21_cos(S21_INFINITY)) == 1);
  ck_assert(isnan(s21_cos(S21_N_INFINITY)) == 1);
}
END_TEST

Suite *test_s21_cos(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_cos]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_cos");

  tcase_add_test(tc, test_cos_positive_double);
  tcase_add_test(tc, test_cos_negative_double);
  tcase_add_test(tc, test_cos_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
