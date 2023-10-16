#include <stdio.h>

#include "blas-l1.h"

int main() {
	const int N = 3;
	float X[] = {1, 2, 3};
	const float alpha = 1.5;

	cblas_sscal(N, alpha, X, 1);

	for (int i = 0; i < N; ++i) {
		printf("%.2f, ", X[i]);
	}

	printf("\n");

	return 0;
}