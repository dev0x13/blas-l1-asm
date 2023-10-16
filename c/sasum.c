#include <math.h>

float cblas_sasum(const int N, const float *X, const int incX) {
  float r = 0.0;
  int i;
  int ix = 0;

  if (incX <= 0) {
    return 0;
  }

  for (i = 0; i < N; i++) {
    r += fabs(X[ix]);
    ix += incX;
  }
  return r;
}