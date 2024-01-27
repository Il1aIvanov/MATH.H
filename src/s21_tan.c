#include "assistive.h"
#include "s21_math.h"

long double s21_tan(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x) || S21_IS_N_INF(x)) return S21_NAN;
  long double num = s21_fmod(x, S21_PI);
  long double tan_res = 0;
  if (num < S21_PI / 4)
    tan_res = opt_tan(num);
  else
    tan_res = 1 / opt_tan(S21_HALF_PI - num);
  return tan_res;
}