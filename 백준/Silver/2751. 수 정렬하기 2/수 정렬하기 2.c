#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef int Element;

void merge_sort(Element* data, int s, int e);
void merge(Element* data, int p, int q, int r);
int compare(Element a, Element b);

int main(void) {
	int N;
	scanf("%d", &N);
	Element* arr = (Element*)malloc(sizeof(Element) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	merge_sort(arr, 0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);

	free(arr);
	return 0;
}

void merge_sort(Element* data, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		merge_sort(data, s, m);
		merge_sort(data, m + 1, e);
		merge(data, s, m, e);
	}
}

void merge(Element* data, int p, int q, int r) {
	Element* temp = (Element*)malloc(sizeof(Element) * (r - p + 1));
	int lc = p, rc = q + 1, pos = 0;

	while (lc <= q && rc <= r) {
		if (compare(data[rc], data[lc]) < 0)
			temp[pos++] = data[rc++];
		else
			temp[pos++] = data[lc++];
	}
	while (lc <= q)
		temp[pos++] = data[lc++];
	while (rc <= r)
		temp[pos++] = data[rc++];

	for (int i = p, j = 0; i <= r; i++, j++)
		data[i] = temp[j];

	free(temp);
}

int compare(Element a, Element b) {
	if (a < b) return -1;
	else if (a > b) return 1;
	return 0;
}