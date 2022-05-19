#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define n 1024+1

double ad[n][n], bd[n][n], cd[n][n];
float af[n][n], bf[n][n], cf[n][n];

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ad[i][j] = (double) rand() / RAND_MAX;
			bd[i][j] = (double) rand() / RAND_MAX;
			af[i][j] = ad[i][j];
			bf[i][j] = bd[i][j];
		}
	}

	// Double
	clock_t start = clock();
	int64_t opsD = 0;
	int	loopsD = 0;
	float secondsD = 0;

	while ( secondsD < 2) {
		loopsD++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				double cc = 0;
				cd[i][j] = 0;
				for (int k = 0; k < n; k++) {
					cd[i][j] += ad[i][k] * bd[k][j];
					cd[i][j] += bd[i][k] * ad[k][j];
				}
				opsD += 2*n;
			}
		}
		secondsD = (float) (clock() - start) / CLOCKS_PER_SEC;
	}
	printf( "double %.4f s total, %d loops %.3f Mops %.3f ns/op\n", secondsD, loopsD, opsD * 1e-6, ( 1e9 * secondsD / opsD));

	// Float
	start = clock();
	int64_t opsF = 0;
	int	loopsF = 0;
	float secondsF = 0;

	while ( secondsF < 2) {
		loopsF++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				double cc = 0;
				cf[i][j] = 0;
				for (int k = 0; k < n; k++) {
					cf[i][j] += af[i][k] * bf[k][j];
					cf[i][j] += bf[i][k] * af[k][j];
				}
				opsF += 2*n;
			}
		}
		secondsF = (float) (clock() - start) / CLOCKS_PER_SEC;
	}
	printf( "float %.4f s total, %d loops %.3f Mops %.3f ns/op\n", secondsF, loopsF, opsF * 1e-6, ( 1e9 * secondsF / opsF));

	return 0;
}
