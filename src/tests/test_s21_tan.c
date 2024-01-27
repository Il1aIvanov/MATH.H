#include "test.h"

START_TEST(test_tan_positive_double) {
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI), tanl(S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(0.25 * S21_PI), tanl(0.25 * S21_PI),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(0.77 * S21_PI), tanl(0.77 * S21_PI),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(2 * S21_PI), tanl(2 * S21_PI), S21_EPSILON);
}
END_TEST

START_TEST(test_tan_negative_double) {
  ck_assert_ldouble_eq_tol(s21_tan(-S21_PI), tanl(-S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(-0.25 * S21_PI), tanl(-0.25 * S21_PI),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(-0.77 * S21_PI), tanl(-0.77 * S21_PI),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(-2 * S21_PI), tanl(-2 * S21_PI),
                           S21_EPSILON);
}
END_TEST

START_TEST(test_tan_specific_value) {
  ck_assert_ldouble_eq_tol(s21_tan(0.0), tanl(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(-0.0), tanl(-0.0), S21_EPSILON);
  ck_assert(isnan(s21_tan(S21_NAN)) == 1);
  ck_assert(isnan(s21_tan(S21_INFINITY)) == 1);
  ck_assert(isnan(s21_tan(S21_N_INFINITY)) == 1);
}
END_TEST

Suite *test_s21_tan(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_tan]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_tan");

  tcase_add_test(tc, test_tan_positive_double);
  tcase_add_test(tc, test_tan_negative_double);
  tcase_add_test(tc, test_tan_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
