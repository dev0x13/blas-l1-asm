void cblas_xerbla(int p, const char *rout, const char *form, ...);

#define SIGN(x) (x >= 0 ? 1 : -1)
#define OFFSET(N, incX) (incX > 0 ?  0 : (N - 1) * -incX)
#define ERROR(x) cblas_xerbla(0, __FILE__, x);