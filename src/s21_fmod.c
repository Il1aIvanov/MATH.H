#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (x == 0.0 && y == 0.0) return S21_NAN;
  if (x == 0.0 || y == 0.0) return 0.0;
  if (S21_IS_INF(y) || S21_IS_N_INF(y)) return x;
  if (S21_IS_INF(x) || S21_IS_N_INF(x) || S21_IS_NAN(x)) return S21_NAN;

  int sign_x = (x > 0) ? 1 : -1;
  int sign_y = (y > 0) ? 1 : -1;

  x *= sign_x;
  y *= sign_y;

  double quotient = x / y;
  double whole_part = (double)((long long)quotient);
  double res = x - whole_part * y;

  return res * sign_x;
}
