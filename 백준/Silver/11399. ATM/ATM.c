#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
	int N, result;
	scanf("%d", &N);
	int* data = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &data[i]);

	qsort(data, N, sizeof(int), compare);

	result = data[0];
	for (int i = 1; i < N; i++) {
		data[i] += data[i - 1];
		result += data[i];
	}
	printf("%d", result);

	return 0;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}