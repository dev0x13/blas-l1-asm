void cblas_sscal(const int N, const float alpha, float *X, const int incX) {
  int i;
  int ix = 0;

  if (incX <= 0) {
    return;
  }

  for (i = 0; i < N; i++) {
    X[ix] *= alpha;
    ix += incX;
  }
}