#include "s21_math.h"

long double s21_floor(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x) || S21_IS_N_INF(x)) {
    return x;
  }

  long long trunc_x = (long long)x;
  double floor_x = (double)trunc_x;
  if (floor_x > x) --floor_x;

  return floor_x;
}
