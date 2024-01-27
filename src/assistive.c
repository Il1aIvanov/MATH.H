#include "assistive.h"

#include "s21_math.h"

long double opt_sin(long double x) {
  long double num = x;
  long double sin_res = num;
  int sign = -1;
  long double fti = 1.;
  long double xx = num * num;
  long double pw = num * xx;
  long double item_i = 1.;
  for (int i = 2; s21_fabs(item_i) > S21_EPSILON; i += 2) {
    fti /= i * (i + 1);
    item_i = sign * pw * fti;
    sin_res += item_i;
    sign *= -1;
    pw *= xx;
  }
  return sin_res;
}

long double opt_cos(long double x) {
  long double num = x;
  long double cos_res = 1.;
  int sign = -1;
  long double fti = 1.;
  long double xx = num * num;
  long double pw = xx;
  long double item_i = 1.;
  for (int i = 2; s21_fabs(item_i) > S21_EPSILON; i += 2) {
    fti /= (i - 1) * i;
    item_i = sign * pw * fti;
    cos_res += item_i;
    sign *= -1;
    pw *= xx;
  }
  return cos_res;
}

long double opt_tan(long double x) {
  long double tan_res = s21_sin(x) / s21_cos(x);
  return tan_res;
}

long double int_pow(long double num, int deg) {
  long double result = 1.;
  while (deg > 0) {
    if (deg % 2 == 0) {
      deg /= 2;
      num *= num;
    } else {
      deg--;
      result *= num;
    }
  }
  return result;
}