#include "assistive.h"
#include "s21_math.h"

long double s21_sin(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x) || S21_IS_N_INF(x)) return S21_NAN;
  long double num = s21_fmod(x, S21_DOUBLE_PI);
  long double sin_res = 0;
  if (num < S21_PI / 4)
    sin_res = opt_sin(num);
  else if (num < 3 * S21_PI / 4)
    sin_res = s21_cos(num - S21_HALF_PI);
  else if (num < S21_PI)
    sin_res = s21_sin(S21_PI - num);
  else
    sin_res = -s21_sin(num - S21_PI);
  return sin_res;
}
