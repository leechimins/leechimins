#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long int result[101] = { 0, 1, 1 };
	for (int i = 3; i <= 100; i++)
		result[i] = result[i - 3] + result[i - 2];

	int TC, N;
	scanf("%d", &TC);

	while (TC--) {
		scanf("%d", &N);
		printf("%lld\n", result[N]);
	}

	return 0;
}