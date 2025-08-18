#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int up_stairs(int n, int* stairs, int memo[][2]);

int main(void) {
	int N, result;
	scanf("%d", &N);
	int stairs[300] = { 0 };
	int memo[300][2] = { 0 };
	for (int i = 0; i < N; i++)
		scanf("%d", &stairs[i]);

	result = up_stairs(N, stairs, memo);
	printf("%d", result);

	return 0;
}

int up_stairs(int n, int* stairs, int memo[][2]) {
	memo[0][1] = stairs[0];

	memo[1][0] = stairs[1];
	memo[1][1] = stairs[1] + stairs[0];

	for (int i = 2; i < n; i++) {
		memo[i][1] = stairs[i] + memo[i - 1][0];
		if (memo[i - 2][0] > memo[i - 2][1])
			memo[i][0] = stairs[i] + memo[i - 2][0];
		else
			memo[i][0] = stairs[i] + memo[i - 2][1];
	}

	if (memo[n - 1][0] > memo[n - 1][1])
		return memo[n - 1][0];
	else
		return memo[n - 1][1];
}