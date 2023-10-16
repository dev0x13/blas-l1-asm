#include <math.h>

#include "common.h"

void cblas_srotg(float *a, float *b, float *c, float *s) {
  const float roe = (fabs(*a) > fabs(*b) ? *a : *b);
  const float scale = fabs(*a) + fabs(*b);
  float r, z;

  if (scale != 0.0) {
    const float aos = *a / scale;
    const float bos = *b / scale;
    r = scale * sqrt(aos * aos + bos * bos);
    r = SIGN(roe) * r;
    *c = *a / r;
    *s = *b / r;
    z = 1.0;
    if (fabs(*a) > fabs(*b))
      z = *s;
    if (fabs(*b) >= fabs(*a) && *c != 0.0)
      z = 1.0 / (*c);
  } else {
    *c = 1.0;
    *s = 0.0;
    r = 0.0;
    z = 0.0;
  }

  *a = r;
  *b = z;
}