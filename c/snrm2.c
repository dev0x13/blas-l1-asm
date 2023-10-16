#include <math.h>

float cblas_snrm2(const int N, const float *X, const int incX) {
  float scale = 0.0;
  float ssq = 1.0;
  int i;
  int ix = 0;

  if (N <= 0 || incX <= 0) {
    return 0;
  } else if (N == 1) {
    return fabs(X[0]);
  }

  for (i = 0; i < N; i++) {
    const float x = X[ix];

    if (x != 0.0) {
      const float ax = fabs(x);

      if (scale < ax) {
        ssq = 1.0 + ssq * (scale / ax) * (scale / ax);
        scale = ax;
      } else {
        ssq += (ax / scale) * (ax / scale);
      }
    }

    ix += incX;
  }

  return scale * sqrt(ssq);
}