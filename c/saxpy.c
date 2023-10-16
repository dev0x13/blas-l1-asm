#include "common.h"

void cblas_saxpy(const int N, const float alpha, const float *X, const int incX,
           float *Y, const int incY) {
  int i;

  if (alpha == 0.0) {
    return;
  }

  if (incX == 1 && incY == 1) {
    const int m = N % 4;

    for (i = 0; i < m; i++) {
      Y[i] += alpha * X[i];
    }

    for (i = m; i + 3 < N; i += 4) {
      Y[i] += alpha * X[i];
      Y[i + 1] += alpha * X[i + 1];
      Y[i + 2] += alpha * X[i + 2];
      Y[i + 3] += alpha * X[i + 3];
    }
  } else {
    int ix = OFFSET(N, incX);
    int iy = OFFSET(N, incY);

    for (i = 0; i < N; i++) {
      Y[iy] += alpha * X[ix];
      ix += incX;
      iy += incY;
    }
  }
}