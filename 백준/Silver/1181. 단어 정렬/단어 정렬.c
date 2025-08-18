#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void merge_sort(char** arr, int s, int e);
void merge(char** arr, int p, int q, int r);
int compare(char* w1, char* w2);

int main(void) {
	int n;
	scanf("%d", &n);
	char** word = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		word[i] = (char*)malloc(sizeof(char) * 51);
		scanf("%s", word[i]);
	}

	merge_sort(word, 0, n - 1);
	printf("%s\n", word[0]);
	for (int i = 1; i < n; i++) {
		if (compare(word[i- 1], word[i]) == 0) continue;
		printf("%s\n", word[i]);
	}

	for (int i = 0; i < n; i++) free(word[i]);
	free(word);
	return 0;
}

void merge_sort(char** arr, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		merge_sort(arr, s, m);
		merge_sort(arr, m + 1, e);
		merge(arr, s, m, e);
	}
}

void merge(char** arr, int p, int q, int r) {
	char** temp = (char**)malloc(sizeof(char*) * (r - p + 1));
	int lc = p, rc = q + 1, pos = 0;

	while (lc <= q && rc <= r) {
		if (compare(arr[rc], arr[lc]) < 0)
			temp[pos++] = arr[rc++];
		else
			temp[pos++] = arr[lc++];
	}
	while (lc <= q) temp[pos++] = arr[lc++];
	while (rc <= r) temp[pos++] = arr[rc++];

	for (int i = p, j = 0; i <= r; i++, j++)
		arr[i] = temp[j];

	free(temp);
}

int compare(char* w1, char* w2) {
	int len1 = strlen(w1), len2 = strlen(w2);

	if (len1 < len2)
		return -2;
	else if (len1 > len2)
		return 2;
	
	for (int i = 0; i < len1; i++)
		if (w1[i] < w2[i])
			return -1;
		else if (w1[i] > w2[i])
			return 1;

	return 0;
}