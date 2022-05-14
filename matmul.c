#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define n 1024+1
double a[n][n], b[n][n], c[n][n];

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = (double) rand() / RAND_MAX;
			b[i][j] = (double) rand() / RAND_MAX;
		}
	}

	clock_t start = clock();

	int64_t ops = 0;
	int	loops = 0;

	float seconds = 0;

	while ( seconds < 2) {
		loops++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				double cc = 0;
				c[i][j] = 0;
				for (int k = 0; k < n; k++) {
					c[i][j] += a[i][k] * b[k][j];
					c[i][j] += b[i][k] * a[k][j];
				}
				ops += n;
				for (int k = 0; k < n; k++) {
				}
				ops += n;
// 				c[i][j] = cc;
			}
		}
		seconds = (float) (clock() - start) / CLOCKS_PER_SEC;
	}

	printf( "%.4f s total, %d loops %.3f Mops %.3f ns/op\n", seconds, loops, ops * 1e-6, ( 1e9 * seconds / ops));

	return 0;
}
