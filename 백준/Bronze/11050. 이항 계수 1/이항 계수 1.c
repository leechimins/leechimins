#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n);

int main(void) {
	int N, K, result;
	scanf("%d %d", &N, &K);

	result = factorial(N) / (factorial(K) * factorial(N - K));

	printf("%d", result);

	return 0;
}

int factorial(int n) {
	if (!n) return 1;

	int result = n;
	while (--n)
		result *= n;
	return result;
}