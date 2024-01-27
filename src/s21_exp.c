#include "assistive.h"
#include "s21_math.h"

long double s21_exp(double x) {
  if (S21_IS_NAN(x)) return S21_NAN;
  if (S21_IS_INF(x)) return S21_INFINITY;
  if (S21_IS_N_INF(x)) return 0;
  long double exp_res = 0;
  if (s21_fabs(x - 1) < 1e-16)
    exp_res = S21_E;
  else if (s21_fabs(x + 1) < 1e-16)
    exp_res = 1. / S21_E;
  else if (s21_fabs(x) < 1e-16)
    exp_res = 1.;
  else if (x < 0)
    exp_res = 1. / s21_exp(-x);
  else {
    int whole_num = s21_floor(x);
    exp_res = int_pow(S21_E, whole_num);

    if (s21_fabs(x - whole_num) > 1e-18) {
      long double dec = x - whole_num;
      long double dec_pow = 1.;
      long double fti = 1.;
      long double pw = 1.;
      long double element = 1.;
      for (int i = 1; s21_fabs(element) > 1e-18; i += 1) {
        fti /= i;
        pw *= dec;
        element = pw * fti;
        dec_pow += element;
      }
      exp_res *= dec_pow;
    }
  }
  return exp_res;
}