#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	int num;
	int count;
} Element;

void merge_sort(Element* data, int s, int e);
void merge(Element* data, int p, int q, int r);
int compare(Element a, Element b);
int combine(Element* oldData[], int size);
int binary_search(Element* data, int key, int low, int high);

int main(void) {
	int n, m, i, j, pos, size;
	scanf("%d", &n);
	Element* cards = (Element*)malloc(sizeof(Element) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &cards[i].num);
		cards[i].count = 1;
	}
	scanf("%d", &m);
	Element* search = (Element*)malloc(sizeof(Element) * m);
	for (i = 0; i < m; i++)
		scanf("%d", &search[i].num);

	merge_sort(cards, 0, n - 1);
	/*for (i = 0; i < n; i++)
		printf("%d %d\n", cards[i].num, cards[i].count);
	printf("\n");*/
	size = combine(&cards, n);
	/*for (i = 0; i < size; i++)
		printf("%d %d\n", cards[i].num, cards[i].count);*/

	for (i = 0; i < m; i++) {
		pos = binary_search(cards, search[i].num, 0, size - 1);
		if (pos < 0)
			search[i].count = 0;
		else
			search[i].count = cards[pos].count;
	}

	for (i = 0; i < m; i++)
		printf("%d ", search[i].count);

	free(cards);
	free(search);
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
	if (a.num < b.num) return -1;
	else if (a.num > b.num) return 1;
	return 0;
}

int combine(Element* oldData[], int size) {
	Element* newData = (Element*)malloc(sizeof(Element) * size);
	int i, j, pos = 0;
	for (i = 0; i < size; i++) {
		for (j = i + 1; (*oldData)[i].num == (*oldData)[j].num; j++)
			(*oldData)[i].count++;
		newData[pos++] = (*oldData)[i];
		i = j - 1;
	}

	/*for (i = 0; i < pos; i++)
		printf("%d %d\n", newData[i].num, newData[i].count);*/

	free(*oldData);
	*oldData = newData;
	newData = NULL;
	return pos;
}

int binary_search(Element* data, int key, int low, int high) {
	if (low > high) return -1;

	int mid = (low + high) / 2;
	if (data[mid].num == key) return mid;
	else if (data[mid].num < key) return binary_search(data, key, mid + 1, high);
	else return binary_search(data, key, low, mid - 1);
}