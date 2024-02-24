#include <stdio.h>

#include "blas-l1.h"

int main() {
  float X[] = {1, -2, 3, 0.34, 2.71828, -3.14};
  const int N = sizeof(X) / sizeof(float);
  const float alpha = 1.5;

  // sscal

  cblas_sscal(N, alpha, X, 1);
  for (int i = 0; i < N; ++i) {
    printf("%.2f, ", X[i]);
  }
  printf("\n");

  // sasum

  float r = cblas_sasum(N, X, 1);
  printf("%.2f\n", r);

  // isamax

  int r1 = cblas_isamax(N, X, 1);
  printf("%d\n", r1);

  // scopy

  float Y[] = {1, 2, 3, 4, 5, 6};
  cblas_scopy(N, X, 1, Y, 1);
  for (int i = 0; i < N; ++i) {
    printf("%.2f %.2f, ", X[i], Y[i]);
  }
  printf("\n");

  return 0;
}