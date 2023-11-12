#include "common.h"

void cblas_srot(const int N, float *X, const int incX, float *Y, const int incY,
                const float c, const float s) {
  int i;
  int ix = OFFSET(N, incX);
  int iy = OFFSET(N, incY);
  for (i = 0; i < N; i++) {
    const float x = X[ix];
    const float y = Y[iy];
    X[ix] = c * x + s * y;
    Y[iy] = -s * x + c * y;
    ix += incX;
    iy += incY;
  }
}