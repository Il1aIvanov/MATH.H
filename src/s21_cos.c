#include "assistive.h"
#include "s21_math.h"

long double s21_cos(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x) || S21_IS_N_INF(x)) return S21_NAN;
  long double num = s21_fmod(x, S21_DOUBLE_PI);
  long double cos_res = 0;
  if (num < S21_PI / 4)
    cos_res = opt_cos(num);
  else if (num < 3 * S21_PI / 4)
    cos_res = opt_sin(S21_HALF_PI - num);
  else if (num <= S21_PI)
    cos_res = -s21_cos(S21_PI - num);
  else
    cos_res = -s21_cos(num - S21_PI);
  return cos_res;
}
