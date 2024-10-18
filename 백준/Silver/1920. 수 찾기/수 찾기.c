#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

int compare(const int* n1, const int* n2);
int isIn(int arr[], int size, int num);

int main(void) {
	int N, M, num[SIZE] = { 0 }, input;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &num[i]);
	qsort(num, N, sizeof(int), compare);

	scanf("%d", &M);
	while (M--) {
		scanf("%d", &input);
		printf("%d\n", isIn(num, N, input));
	}

	return 0;
}

int compare(const int* n1, const int* n2) {
	if (*n1 < *n2) return -1;
	else if (*n1 > *n2) return 1;
	else return 0;
}

int isIn(int arr[], int size, int num) {
	int start = 0, end = size-1, med;
	while (start <= end) {
		med = (start + end) / 2;
		if (arr[med] == num) return 1;
		else if (arr[med] < num) start = med + 1;
		else end = med - 1;
	}

	return 0;
}