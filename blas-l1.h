void cblas_srotg(float *a, float *b, float *c, float *s);
void cblas_srotmg(float *d1, float *d2, float *b1, const float b2, float *P);
void cblas_srot(const int N, float *X, const int incX, float *Y, const int incY,
                const float c, const float s);
void cblas_srotm(const int N, float *X, const int incX, float *Y,
                 const int incY, const float *P);
void cblas_sswap(const int N, float *X, const int incX, float *Y,
                 const int incY);
void cblas_sscal(const int N, const float alpha, float *X, const int incX);
void cblas_scopy(const int N, const float *X, const int incX, float *Y,
                 const int incY);
void cblas_saxpy(const int N, const float alpha, const float *X, const int incX,
                 float *Y, const int incY);
float cblas_sdot(const int N, const float *X, const int incX, const float *Y,
                 const int incY);
float cblas_sdsdot(const int N, const float alpha, const float *X,
                   const int incX, const float *Y, const int incY);
float cblas_snrm2(const int N, const float *X, const int incX);
float cblas_sasum(const int N, const float *X, const int incX);
int cblas_isamax(const int N, const float *X, const int incX);
