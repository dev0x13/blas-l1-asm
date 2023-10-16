#include "common.h"

void cblas_scopy(const int N, const float *X, const int incX, float *Y,
           const int incY) {
  int i;
  int ix = OFFSET(N, incX);
  int iy = OFFSET(N, incY);

  for (i = 0; i < N; i++) {
    Y[iy] = X[ix];
    ix += incX;
    iy += incY;
  }
}