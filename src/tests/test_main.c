#include "test.h"

int main(void) {
  Suite *s21_math_tests[] = {
      test_s21_fabs(), test_s21_floor(), test_s21_fmod(), test_s21_log(),
      test_s21_sqrt(), test_s21_abs(),   test_s21_acos(), test_s21_asin(),
      test_s21_atan(), test_s21_ceil(),  test_s21_sin(),  test_s21_cos(),
      test_s21_tan(),  test_s21_pow(),   test_s21_exp(),  NULL};

  int number_failed = 0;

  for (int i = 0; s21_math_tests[i] != NULL; ++i) {
    SRunner *sr = srunner_create(s21_math_tests[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf(COLOR_CYAN_LEFT "[Total failed %d tests]\n" COLOR_CYAN_RIGHT,
         number_failed);

  return number_failed;
}
