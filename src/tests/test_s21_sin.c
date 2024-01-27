#include "test.h"

START_TEST(test_sin_positive_double) {
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI), sin(S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI / 2), sin(S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(3 * S21_PI / 2), sin(3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(2 * S21_PI), sin(2 * S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(5 * S21_PI / 6), sinl(5 * S21_PI / 6),
                           S21_EPSILON);
}
END_TEST

START_TEST(test_sin_negative_double) {
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI), sinl(-S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI / 2), sinl(-S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(-3 * S21_PI / 2), sinl(-3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(-2 * S21_PI), sinl(-2 * S21_PI),
                           S21_EPSILON);
}
END_TEST

START_TEST(test_sin_specific_value) {
  ck_assert_ldouble_eq_tol(s21_sin(0.0), sinl(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(-0.0), sinl(-0.0), S21_EPSILON);
  ck_assert(isnan(s21_sin(S21_NAN)) == 1);
  ck_assert(isnan(s21_sin(S21_INFINITY)) == 1);
  ck_assert(isnan(s21_sin(S21_N_INFINITY)) == 1);
}
END_TEST

Suite *test_s21_sin(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_sin]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_sin");

  tcase_add_test(tc, test_sin_positive_double);
  tcase_add_test(tc, test_sin_negative_double);
  tcase_add_test(tc, test_sin_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
