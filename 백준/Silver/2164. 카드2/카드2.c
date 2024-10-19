#include <stdio.h>
#include <stdlib.h>

int execute(int num[], int n);
int step(int num[], int n);

int main(void) {
	int N, ans;
	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * (N + 1) / 2);
	if (N % 2) {
		arr[0] = N;
		for (int i = 1; i <= N / 2; i++) arr[i] = i * 2;
	}
	else for (int i = 0; i < N / 2; i++) arr[i] = (i + 1) * 2;

	ans = execute(arr, (N+1)/2);
	printf("%d", ans);

	free(arr);
	return 0;
}

int execute(int num[], int n) {
	while (n > 1) n = step(num, n);
	return num[0];
}

int step(int num[], int n) {
	int size = (n + 1) / 2;
	int* result = (int*)malloc(sizeof(int) * size);
	if (n % 2) {
		result[0] = num[n - 1];
		for (int i = 1; i <= n / 2; i++) result[i] = num[2 * i - 1];
	}
	else for (int i = 0; i < n / 2; i++) result[i] = num[2 * i + 1];

	for (int i = 0; i < size; i++) num[i] = result[i];

	free(result);
	return size;
}