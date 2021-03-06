#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long Factorial(long a) {
	if (a <= 1)
		return 1;

	long res = a;

	while (--a > 0) {
		res = res * a;
	}

	return res;
}

//  Negative roots lel
float PowWithNegative(float n, float p) {

	if (n < 0) {
		return pow(n * -1, p) * -1;
	}
	else {
		return pow(n, p);
	}
}

// http://www.1728.org/cubic2.htm
// b = 0, c = 0
void SolveKindOfCubic(float a, float d) {
	printf("Solving cubic equiation for a = %f; b = 0; c = 0; d = %f;\n", a, d);

	float g = d / a;

	float hsqrt = sqrt(g * g / 4);

	float p = 1.0 / 3.0;

	float s = -(g / 2) + hsqrt;
	s = PowWithNegative(s, p);

	float u = -(g / 2) - hsqrt;
	u = PowWithNegative(u, p);

	// ((S+U) - (b/(3*a)))
	float x1 = s + u;

	// -(S + U)/2 - (b/3a) + i*(S-U)*(3)^.5
	float x2r = -1 * (s + u) / 2;
	float x2i = ((s - u) / 2) * pow(3, 0.5);

	printf("x1 = %f;\nx2 = %f + i*%f;\nx3 = %f - i*%f", x1, x2r, x2i, x2r, x2i);
}

static long CountEvenColPositiveCells(long** matrix, long n, long m) {
	long count = 0;

	for (long i = 1; i < n; i = i + 2) {
		for (long k = 0; k < m; k++) {
			if (matrix[i][k] > 0) {
				count++;
			}
		}
	}

	return count;
}

long** ReadMatrix(long n, long m) {
	long** res = new long*[n];
	for (long i = 0; i < n; i++) {
		res[i] = new long[m];
		for (long k = 0; k < m; k++) {
			scanf("%ld", &res[i][k]);
			printf("%ld ", res[i][k]);
		}
		printf("\n");
	}
	return res;
}

int main(int argc, char *argv[]) {

	if (argc > 2) {
		freopen(argv[2], "r", stdin);
	}
	else {
		freopen("input.txt", "r", stdin);
	}

	long n1 = 5;
	long n2 = 6;

	int amount;
	scanf("%d", &amount);

	while (amount--) {

		printf("T(5, 5)\n");
		long** m1 = ReadMatrix(n1, n1);
		printf("D(6, 6)\n");
		long** m2 = ReadMatrix(n2, n2);
		printf("\n");

		long c1, c2;
		c1 = CountEvenColPositiveCells(m1, n1, n1);
		c2 = CountEvenColPositiveCells(m2, n2, n2);
		printf("a = %ld\n", c1);
		printf("b = %ld\n", c2);

		float a = 3 * Factorial(c1 + c2);
		float d = 2 * Factorial(c1);

		SolveKindOfCubic(a, d);

		long i;
		for (i = 0; i < n1; i++) {
			delete m1[i];
		}
		for (i = 0; i < n2; i++) {
			delete m2[i];
		}
		delete m1;
		delete m2;
	}

	return 0;
}

