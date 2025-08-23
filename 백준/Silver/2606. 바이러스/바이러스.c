#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int computer[101][101] = { { 0 }, { 0, 1 } };
	int N, N2, M, c1, c2, result;

	scanf("%d", &N);
	scanf("%d", &M);
	N2 = N * N;

	while (M--) {
		scanf("%d %d", &c1, &c2);

		computer[c1][c2] = 1;
		computer[c2][c1] = 1;
	}

	for (int i = 0; i < N2; i++) {
		if (computer[i % N + 1][i % N + 1] == 0)
			continue;

		for (int j = 1; j <= N; j++) {
			if (computer[i % N + 1][j] == 1)
				computer[j][j] = 2;
		}
	}

	result = N - 1;
	for (int i = 1; i <= N; i++)
		if (computer[i][i] == 0)
			result--;

	printf("%d", result);

	return 0;
}