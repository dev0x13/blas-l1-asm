#include "common.h"

float cblas_sdot(const int N, const float  *X, const int incX,
           const float  *Y, const int incY) {
  float r = 0.0;
  int i;
  int ix = OFFSET(N, incX);
  int iy = OFFSET(N, incY);

  for (i = 0; i < N; i++) {
    r += X[ix] * Y[iy];
    ix += incX;
    iy += incY;
  }

  return r;
}