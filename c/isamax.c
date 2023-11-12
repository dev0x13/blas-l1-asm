#include "math.h"

int cblas_isamax(const int N, const float *X, const int incX) {
  float max = 0.0;
  int ix = 0;
  int i;
  int result = 0;

  if (incX <= 0) {
    return 0;
  }

  for (i = 0; i < N; i++) {
    if (fabs(X[ix]) > max) {
      max = fabs(X[ix]);
      result = i;
    }
    ix += incX;
  }

  return result;
}