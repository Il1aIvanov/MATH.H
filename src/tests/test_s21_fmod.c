#include "test.h"

START_TEST(test_fmod_positive_int) {
  ck_assert_double_eq_tol(s21_fmod(1, 100), fmod(1, 100), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(228, 10), fmod(228, 10), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(26, 2), fmod(26, 2), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(50, 4), fmod(50, 4), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(1488, 13), fmod(1488, 13), S21_EPSILON);
}
END_TEST

START_TEST(test_fmod_negative_int) {
  ck_assert_double_eq_tol(s21_fmod(-1, -1), fmod(-1, -1), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(-5, -1), fmod(-5, -1), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(-1488, -12), fmod(-1488, -12), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(-29, 3), fmod(-29, 3), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(-69696969, 99999), fmod(-69696969, 99999),
                          S21_EPSILON);
}
END_TEST

START_TEST(test_fmod_positive_double) {
  ck_assert_double_eq_tol(s21_fmod(0.00034, -1), fmod(0.00034, -1),
                          S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(1.68234, 2), fmod(1.68234, 2), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(6.6432, 3), fmod(6.6432, 3), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(28.969, 0.333), fmod(28.969, 0.333),
                          S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(74.972, 7.0), fmod(74.972, 7.0),
                          S21_EPSILON);
}
END_TEST

START_TEST(test_fmod_negative_double) {
  ck_assert_double_eq_tol(s21_fmod(-0.00001, 0.000001),
                          fmod(-0.00001, 0.000001), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(-0.992347, 0.3), fmod(-0.992347, 0.3),
                          S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(-2.682, -0.5), fmod(-2.682, -0.5),
                          S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(-14.79635, -10), fmod(-14.79635, -10),
                          S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(-46.942, 8.2), fmod(-46.942, 8.2),
                          S21_EPSILON);
}
END_TEST

START_TEST(test_fmod_specific_value) {
  ck_assert_double_eq_tol(s21_fmod(0.0, 1), fmod(0.0, 1), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(+0.0, 1.1), fmod(+0.0, 1.1), S21_EPSILON);
  ck_assert_double_eq_tol(s21_fmod(-0.0, 1.1111), fmod(-0.0, 1.1111),
                          S21_EPSILON);
  ck_assert_double_eq(s21_fmod(-1001, S21_INFINITY), fmod(-1001, S21_INFINITY));
  ck_assert_double_eq(s21_fmod(0.25, S21_N_INFINITY),
                      fmod(0.25, S21_N_INFINITY));
  ck_assert(isnan(s21_fmod(0.0, 0.0)) == 1);
  ck_assert(isnan(s21_fmod(+0.0, 0.0)) == 1);
  ck_assert(isnan(s21_fmod(-0.0, 0.0)) == 1);
  ck_assert(isnan(s21_fmod(S21_NAN, 1)) == 1);
  ck_assert(isnan(s21_fmod(S21_INFINITY, -1001)) == 1);
  ck_assert(isnan(s21_fmod(S21_N_INFINITY, 0.25)) == 1);
  ck_assert(isnan(s21_fmod(1, S21_NAN)) == 1);
}
END_TEST

Suite *test_s21_fmod() {
  Suite *s =
      suite_create(COLOR_YELLOW_LEFT "[Test s21_fmod]" COLOR_YELLOW_RIGHT);
  TCase *tc = tcase_create("s21_fmod");

  tcase_add_test(tc, test_fmod_positive_int);
  tcase_add_test(tc, test_fmod_negative_int);
  tcase_add_test(tc, test_fmod_positive_double);
  tcase_add_test(tc, test_fmod_negative_double);
  tcase_add_test(tc, test_fmod_specific_value);

  suite_add_tcase(s, tc);
  return s;
}
