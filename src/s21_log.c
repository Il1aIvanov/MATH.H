#include "s21_math.h"

long double s21_log(double x) {
  if (x < 0.0 || x == S21_N_INFINITY || S21_IS_NAN(x)) return S21_NAN;
  if (x == 0) return S21_N_INFINITY;
  if (x == 1) return 0.0;
  if (x == S21_INFINITY) return S21_INFINITY;

  long double result = 0.0;

  while (x <= 0.5) {
    x *= 2;
    result -= S21_LN_2;
  }

  while (x > 2.0) {
    x /= 2;
    result += S21_LN_2;
  }

  long double term = (x - 1.0) / x;
  long double term_power = term;

  for (int n = 1; n <= 100 || term_power > S21_EPSILON; ++n) {
    result += term_power / n;
    term_power *= term;
  }

  return result;
}
