#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <math.h>

#define COLOR_YELLOW_LEFT "\x1b[33m"
#define COLOR_YELLOW_RIGHT "\x1b[0m"

#define COLOR_CYAN_LEFT "\x1b[36m"
#define COLOR_CYAN_RIGHT "\x1b[0m"

#include "../s21_math.h"

Suite *test_s21_fabs(void);
Suite *test_s21_floor(void);
Suite *test_s21_fmod(void);
Suite *test_s21_log(void);
Suite *test_s21_sqrt(void);

Suite *test_s21_abs(void);
Suite *test_s21_acos(void);
Suite *test_s21_asin(void);
Suite *test_s21_atan(void);
Suite *test_s21_ceil(void);

Suite *test_s21_sin(void);
Suite *test_s21_cos(void);
Suite *test_s21_tan(void);
Suite *test_s21_pow(void);
Suite *test_s21_exp(void);

#endif
