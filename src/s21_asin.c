#include "s21_math.h"

long double s21_asin(double x) {
  long double asin_result = 0.0;
  if (x == 1.0 || x == -1.0) asin_result = S21_PI / (2 * x);
  if (s21_fabs(x) < 1.0) {
    asin_result = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
  }
  if (s21_fabs(x) > 1 || S21_IS_NAN(x)) return S21_NAN;
  return asin_result;
}
