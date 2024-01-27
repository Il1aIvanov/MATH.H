#include "test.h"

START_TEST(test_fabs_positive_int) {
  ck_assert_double_eq_tol(s21_fabs(1.0), fabs(1.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(228.0), fabs(228.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(26.0), fabs(26.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(50.0), fabs(50.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(1488.0), fabs(1488.0), S21_EPSILON);
}
END_TEST

START_TEST(test_fabs_negative_int) {
  ck_assert_double_eq_tol(s21_fabs(-1.0), fabs(-1.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(-5.0), fabs(-5.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(-1488.0), fabs(-1488.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(-29.0), fabs(-29.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(-69696969.0), fabs(-69696969.0),
                          S21_EPSILON);
}
END_TEST

START_TEST(test_fabs_positive_double) {
  ck_assert_double_eq_tol(s21_fabs(0.00034), fabs(0.00034), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(1.68234), fabs(1.68234), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(6.6432), fabs(6.6432), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(28.969), fabs(28.969), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(74.972), fabs(74.972), S21_EPSILON);
}
END_TEST

START_TEST(test_fabs_negative_double) {
  ck_assert_double_eq_tol(s21_fabs(-0.00001), fabs(-0.00001), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(-0.992347), fabs(-0.992347), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(-2.682), fabs(-2.682), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(-14.79635), fabs(-14.79635), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(-46.942), fabs(-46.942), S21_EPSILON);
}
END_TEST

START_TEST(test_fabs_specific_value) {
  ck_assert_double_eq_tol(s21_fabs(0.0), fabs(0.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(+0.0), fabs(+0.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fabs(-0.0), fabs(-0.0), S21_EPSILON);
  ck_assert(isnan(s21_fabs(S21_NAN)) == 1);
  ck_assert_double_eq(s21_fabs(S21_INFINITY), fabs(S21_INFINITY));
  ck_assert_double_eq(s21_fabs(S21_N_INFINITY), fabs(S21_N_INFINITY));
}
END_TEST

Suite *test_s21_fabs(void) {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_fabs]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_fabs");

  tcase_add_test(tc, test_fabs_positive_int);
  tcase_add_test(tc, test_fabs_negative_int);
  tcase_add_test(tc, test_fabs_positive_double);
  tcase_add_test(tc, test_fabs_negative_double);
  tcase_add_test(tc, test_fabs_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
