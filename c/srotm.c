#include "common.h"

void cblas_srotm(const int N, float *X, const int incX, float *Y,
                 const int incY, const float *P) {
  int n;
  int i = OFFSET(N, incX);
  int j = OFFSET(N, incY);

  float h11, h21, h12, h22;

  if (P[0] == -1.0) {
    h11 = P[1];
    h21 = P[2];
    h12 = P[3];
    h22 = P[4];
  } else if (P[0] == 0.0) {
    h11 = 1.0;
    h21 = P[2];
    h12 = P[3];
    h22 = 1.0;
  } else if (P[0] == 1.0) {
    h11 = P[1];
    h21 = -1.0;
    h12 = 1.0;
    h22 = P[4];
  } else if (P[0] == -2.0) {
    return;
  } else {
    ERROR("unrecognized value of P[0]");
    return;
  }

  for (n = 0; n < N; n++) {
    const float w = X[i];
    const float z = Y[j];
    X[i] = h11 * w + h12 * z;
    Y[j] = h21 * w + h22 * z;
    i += incX;
    j += incY;
  }
}