#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int num, int* memo);

int main(void) {
	int T, n, result;
	int memo[12] = { 0, 1, 2, 4 };
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		result = sum(n, memo);
		printf("%d\n", result);
	}

	return 0;
}

int sum(int num, int* memo) {
	if (memo[num] > 0)
		return memo[num];

	memo[num] = sum(num - 1, memo);
	if (num > 2)
		memo[num] += sum(num - 2, memo);
	if (num > 3)
		memo[num] += sum(num - 3, memo);

	return memo[num];
}