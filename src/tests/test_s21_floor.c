#include "test.h"

START_TEST(test_floor_positive_int) {
  ck_assert_double_eq_tol(s21_floor(1), floor(1), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(228), floor(228), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(26), floor(26), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(50), floor(50), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(1488), floor(1488), S21_EPSILON);
}
END_TEST

START_TEST(test_floor_negative_int) {
  ck_assert_double_eq_tol(s21_floor(-1), floor(-1), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(-5), floor(-5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(-1488), floor(-1488), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(-29), floor(-29), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(-69696969), floor(-69696969), S21_EPSILON);
}
END_TEST

START_TEST(test_floor_positive_double) {
  ck_assert_double_eq_tol(s21_floor(0.00034), floor(0.00034), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(1.68234), floor(1.68234), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(6.6432), floor(6.6432), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(28.969), floor(28.969), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(74.972), floor(74.972), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(9999999999.99999), floor(9999999999.99999),
                          S21_EPSILON);
}
END_TEST

START_TEST(test_floor_negative_double) {
  ck_assert_double_eq_tol(s21_floor(-0.00001), floor(-0.00001), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(-0.992347), floor(-0.992347), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(-2.682), floor(-2.682), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(-14.79635), floor(-14.79635), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(-46.942), floor(-46.942), S21_EPSILON);
}
END_TEST

START_TEST(test_floor_specific_value) {
  ck_assert_double_eq_tol(s21_floor(0.0), floor(0.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(+0.0), floor(+0.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_floor(-0.0), floor(-0.0), S21_EPSILON);
  ck_assert(isnan(s21_floor(S21_NAN)) == 1);
  ck_assert_double_eq(s21_floor(S21_INFINITY), floor(S21_INFINITY));
  ck_assert_double_eq(s21_floor(S21_N_INFINITY), floor(S21_N_INFINITY));
}
END_TEST

Suite *test_s21_floor() {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_floor]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_floor");

  tcase_add_test(tc, test_floor_positive_int);
  tcase_add_test(tc, test_floor_negative_int);
  tcase_add_test(tc, test_floor_positive_double);
  tcase_add_test(tc, test_floor_negative_double);
  tcase_add_test(tc, test_floor_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
