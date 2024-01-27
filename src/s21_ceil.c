#include "s21_math.h"

long double s21_ceil(double x) {
  long double ceil_res = (long long)x;
  if (S21_IS_NAN(x)) {
    ceil_res = S21_NAN;
  } else if (S21_IS_INF(x)) {
    ceil_res = S21_INFINITY;
  } else if (S21_IS_N_INF(x)) {
    ceil_res = S21_N_INFINITY;
  } else if (x > 0 && x != ceil_res) {
    ceil_res += 1;
  }
  return ceil_res;
}
