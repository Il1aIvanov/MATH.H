#include "s21_math.h"

long double s21_acos(double x) {
  long double acos_result = 0.0;
  if (x < 1.0 && x > 0.0) acos_result = s21_atan(s21_sqrt(1 - x * x) / x);
  if (x < 0.0 && x > -1.0)
    acos_result = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  if (s21_fabs(x - 1) < S21_EPSILON) acos_result = 0;
  if (s21_fabs(x + 1) < S21_EPSILON) acos_result = S21_PI;
  if (s21_fabs(x) < S21_EPSILON) acos_result = S21_PI / 2;
  if (s21_fabs(x) > 1 || S21_IS_NAN(x)) return S21_NAN;
  return acos_result;
}
