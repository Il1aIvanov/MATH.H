#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>
#include <stdlib.h>

#define S21_INFINITY 1.0 / 0.0
#define S21_N_INFINITY -1.0 / 0.0
#define S21_NAN 0.0 / 0.0

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INFINITY)
#define S21_IS_N_INF(x) (x == S21_N_INFINITY)

#define S21_PI 3.14159265358979323846l
#define S21_HALF_PI 1.57079632679489661923l
#define S21_DOUBLE_PI 6.28318530717958647692l

#define S21_E 2.71828182845904523536l

#define S21_EPSILON 1e-6
#define S21_LN_2 0.693147180559945309417232121458176568l

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
