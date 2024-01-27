#include "test.h"

START_TEST(test_exp_positive_int) {
  ck_assert_ldouble_eq_tol(s21_exp(1), expl(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(17), expl(17), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(26), expl(26), 1e-4);
  ck_assert_ldouble_eq_tol(s21_exp(35), expl(35), 1e6);
}
END_TEST

START_TEST(test_exp_negative_int) {
  ck_assert_ldouble_eq_tol(s21_exp(-1), expl(-1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(-5), expl(-5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(-14), expl(-14), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(-29), expl(-29), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(-63), expl(-63), S21_EPSILON);
}
END_TEST

START_TEST(test_exp_positive_double) {
  ck_assert_ldouble_eq_tol(s21_exp(0.00034), expl(0.00034), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(1.68234), expl(1.68234), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(6.643), expl(6.643), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(28.969), expl(28.969), 1e-3);
}
END_TEST

START_TEST(test_exp_negative_double) {
  ck_assert_ldouble_eq_tol(s21_exp(-0.00001), expl(-0.00001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(-0.992347), expl(-0.992347), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(-2.682), expl(-2.682), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(-14.79635), expl(-14.79635), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(-46.942), expl(-46.942), S21_EPSILON);
}
END_TEST

START_TEST(test_exp_specific_value) {
  ck_assert_ldouble_eq_tol(s21_exp(0.0), expl(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(+0.0), expl(+0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_exp(-0.0), expl(-0.0), S21_EPSILON);
  ck_assert(isnan(s21_exp(S21_NAN)) == 1);
  ck_assert_ldouble_eq(s21_exp(S21_INFINITY), expl(S21_INFINITY));
  ck_assert_ldouble_eq(s21_exp(S21_N_INFINITY), expl(S21_N_INFINITY));
}
END_TEST

Suite *test_s21_exp(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_exp]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_exp");

  tcase_add_test(tc, test_exp_positive_int);
  tcase_add_test(tc, test_exp_negative_int);
  tcase_add_test(tc, test_exp_positive_double);
  tcase_add_test(tc, test_exp_negative_double);
  tcase_add_test(tc, test_exp_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
