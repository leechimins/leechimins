#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, M, s, e, result;
	scanf("%d %d", &N, &M);

	int data[100001];
	int sum[100001] = { 0 };

	for (int i = 1; i <= N; i++) {
		scanf("%d", &data[i]);
		sum[i] = sum[i - 1] + data[i];
	}

	while(M--) {
		scanf("%d %d", &s, &e);
		result = sum[e] - sum[s - 1];
		printf("%d\n", result);
	}
	
	return 0;
}