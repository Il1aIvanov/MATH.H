#include "s21_math.h"

long double s21_atan(double x) {
  if (x > 1.0) return (S21_PI / 2) - (s21_atan(1 / x));
  if (x < -1.0) return (-S21_PI / 2) - (s21_atan(1 / x));
  if (x == S21_INFINITY || x == S21_N_INFINITY) return S21_PI / 2;
  if (x == 0.0) return 0.0;
  if (x == 1.0 || x == -1.0) return S21_PI / (4.0 * x);
  long double item_i = 1.0;
  long double atan_result = 0.0;
  for (int i = 0; s21_fabs(item_i) >= S21_EPSILON; i++) {
    item_i = (s21_pow(-1, i) * s21_pow(x, (1 + 2 * i))) / (1 + 2 * i);
    atan_result += item_i;
  }
  return atan_result;
}
