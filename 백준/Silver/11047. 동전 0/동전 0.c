#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main(void) {
	int N, K, result = 0;
	scanf("%d %d", &N, &K);
	int* coin = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &coin[i]);

	for (int i = N - 1; i >= 0; i--) {
		result += K / coin[i];
		K %= coin[i];
	}

	printf("%d", result);

	free(coin);
	return 0;
}