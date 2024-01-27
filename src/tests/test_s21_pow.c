#include "test.h"

START_TEST(test_pow_positive_int) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 2), powl(1, 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(5, 3), powl(5, 3), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(7, 2), powl(7, 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(1, -2), powl(1, -2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(5, -3), powl(5, -3), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(7, -2), powl(7, -2), S21_EPSILON);
}
END_TEST

START_TEST(test_pow_negative_int) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 2), powl(-1, 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-5, 3), powl(-5, 3), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-7, 2), powl(-7, 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-1, -2), powl(-1, -2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-5, -3), powl(-5, -3), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-7, -2), powl(-7, -2), S21_EPSILON);
}
END_TEST

START_TEST(test_pow_positive_double) {
  ck_assert_ldouble_eq_tol(s21_pow(1.25, 2.13), powl(1.25, 2.13), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(5.55, 3.33), powl(5.55, 3.33), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(7.71, 2.21), powl(7.71, 2.21), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(1.25, -2.13), powl(1.25, -2.13),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(5.55, -3.33), powl(5.55, -3.33),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(7.71, -2.21), powl(7.71, -2.21),
                           S21_EPSILON);
}
END_TEST

START_TEST(test_pow_negative_double) {
  ck_assert(isnan(s21_pow(-1.25, 2.21)) == 1);
  ck_assert(isnan(s21_pow(-5.55, 3.33)) == 1);
  ck_assert(isnan(s21_pow(-7.71, 2.21)) == 1);
  ck_assert(isnan(s21_pow(-1.25, -2.13)) == 1);
  ck_assert(isnan(s21_pow(-5.55, -3.33)) == 1);
  ck_assert(isnan(s21_pow(-7.71, -2.21)) == 1);
}

START_TEST(test_pow_different_value) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 2.25), powl(1, 2.25), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(5.25, 3), powl(5.25, 3), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(1.15, -2.21), powl(1.15, -2.21),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-7.21, -2), powl(-7.21, -2), S21_EPSILON);
}
END_TEST

START_TEST(test_pow_specific_value) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 0), powl(1, 0), S21_EPSILON);
  ck_assert_ldouble_eq(s21_pow(-2.21, S21_INFINITY), powl(-2.21, S21_INFINITY));
  ck_assert_ldouble_eq(s21_pow(S21_N_INFINITY, 2.21),
                       powl(S21_N_INFINITY, 2.21));
  ck_assert_ldouble_eq(s21_pow(S21_N_INFINITY, 2), powl(S21_N_INFINITY, 2));
  ck_assert_ldouble_eq(s21_pow(S21_N_INFINITY, 4.21),
                       powl(S21_N_INFINITY, 4.21));
  ck_assert_ldouble_eq_tol(s21_pow(S21_N_INFINITY, -4.21),
                           powl(S21_N_INFINITY, -4.21), S21_EPSILON);
}
END_TEST

Suite *test_s21_pow(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_pow]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_pow");

  tcase_add_test(tc, test_pow_positive_int);
  tcase_add_test(tc, test_pow_negative_int);
  tcase_add_test(tc, test_pow_positive_double);
  tcase_add_test(tc, test_pow_negative_double);
  tcase_add_test(tc, test_pow_different_value);
  tcase_add_test(tc, test_pow_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
