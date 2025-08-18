#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ad[21];
	char pw[21];
} Info;
typedef char Addr[21];

int compare(const void* a, const void* b);
int binary_search(Info* data, char* key, int low, int high);

int main(void) {
	int N, M, index;
	scanf("%d %d", &N, &M);
	Info* data = (Info*)malloc(sizeof(Info) * N);
	Addr* find = (Addr*)malloc(sizeof(Addr) * M);
	for (int i = 0; i < N; i++)
		scanf("%s %s", &data[i].ad, &data[i].pw);
	for (int i = 0; i < M; i++)
		scanf("%s", &find[i]);

	qsort(data, N, sizeof(Info), compare);
	for (int i = 0; i < M; i++) {
		index = binary_search(data, find[i], 0, N - 1);
		printf("%s\n", data[index].pw);
	}

	return 0;
}

int compare(const void* a, const void* b) {
	Info A = *(Info*)a;
	Info B = *(Info*)b;

	if (strcmp(A.ad, B.ad))
		return strcmp(A.ad, B.ad);
	else
		return strcmp(A.pw, B.pw);
}

int binary_search(Info* data, Addr key, int low, int high) {
	if (low > high) return -1;

	int mid = (low + high) / 2;
	if (strcmp(data[mid].ad, key) == 0)
		return mid;
	else if (strcmp(data[mid].ad, key) < 0)
		return binary_search(data, key, mid + 1, high);
	else
		return binary_search(data, key, low, mid - 1);
}