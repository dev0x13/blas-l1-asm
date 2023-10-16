#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

void cblas_xerbla(int p, const char *rout, const char *form, ...) {
  va_list ap;

  va_start(ap, form);

  if (p) {
    fprintf(stderr, "Parameter %d to routine %s was incorrect\n", p, rout);
  }

  vfprintf(stderr, form, ap);
  va_end(ap);

  abort();
}