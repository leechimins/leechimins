#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N;
	int result[1001] = { 1, 1 };
	scanf("%d", &N);

	for (int i = 2; i <= N; i++)
		result[i] = (result[i - 2] * 2 + result[i - 1]) % 10007;

	printf("%d", result[N]);

	return 0;
}