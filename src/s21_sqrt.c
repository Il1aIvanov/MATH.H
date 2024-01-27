#include "s21_math.h"

long double s21_sqrt(double x) {
  if (x < 0.0 || S21_IS_NAN(x) || x == S21_N_INFINITY) return S21_NAN;
  if (x == S21_INFINITY || x == 0.0) return x;
  return s21_pow(x, 0.5);
}
