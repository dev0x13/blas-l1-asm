#include "common.h"

void cblas_sswap(const int N, float *X, const int incX, float *Y,
                 const int incY) {
  int i;
  int ix = OFFSET(N, incX);
  int iy = OFFSET(N, incY);
  for (i = 0; i < N; i++) {
    const float tmp = X[ix];
    X[ix] = Y[iy];
    Y[iy] = tmp;
    ix += incX;
    iy += incY;
  }
}