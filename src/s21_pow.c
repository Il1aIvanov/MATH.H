#include "assistive.h"
#include "s21_math.h"

long double s21_pow(double base, double exp) {
  if (S21_IS_NAN(base) || S21_IS_NAN(exp)) return S21_NAN;
  if (S21_IS_INF(exp) || ((S21_IS_INF(base) || S21_IS_N_INF(base)) && exp > 0))
    return S21_INFINITY;
  if (S21_IS_N_INF(exp) ||
      ((S21_IS_INF(base) || S21_IS_N_INF(base)) && exp < 0))
    return 0;
  long double pow_res = 0;
  if (exp < 0)
    pow_res = 1 / s21_pow(base, -exp);
  else if (s21_fabs(exp - (int)exp) <= 1e-16)
    pow_res = int_pow(base, (int)exp);
  else {
    int whole_num = (int)s21_floor(exp);
    pow_res = int_pow(base, whole_num);

    long double dec = exp - whole_num;
    pow_res *= s21_exp(dec * s21_log(base));
  }
  return pow_res;
}