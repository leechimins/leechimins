#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

typedef char Pokemon[21];

typedef struct {
	int index;
	char name[21];
} Element;

int str_to_num(char* str);
void merge_sort(Element* data, int s, int e);
void merge(Element* data, int p, int q, int r);
int binary_search(Element* data, char* key, int low, int high);

int main(void) {
	int N, M, index;
	scanf("%d %d", &N, &M);
	char input[21];
	Pokemon* pokemon = (Pokemon*)malloc(sizeof(Pokemon) * N);
	Element* book = (Element*)malloc(sizeof(Element) * N);
	for (int i = 0; i < N; i++) {
		scanf("%s", pokemon[i]);
		strcpy(book[i].name, pokemon[i]);
		book[i].index = i + 1;
	}
	merge_sort(book, 0, N - 1);

	for (int i = 0; i < M; i++) {
		scanf("%s", input);
		index = str_to_num(input);
		if (index > 0)
			printf("%s\n", pokemon[index - 1]);
		else
			printf("%d\n", binary_search(book, input, 0, N - 1));
	}

	free(pokemon);
	free(book);
	return 0;
}

int str_to_num(char* str) {
	int result = 0;

	while (*str) {
		result *= 10;
		if (isdigit(*str) == 0)
			return -1;
		result += *str - '0';
		str++;
	}

	return result;
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
		if (strcmp(data[rc].name, data[lc].name) < 0)
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

int binary_search(Element* data, char* key, int low, int high) {
	if (low > high) return -1;

	int mid = (low + high) / 2;
	if (strcmp(data[mid].name, key) == 0)
		return data[mid].index;
	else if (strcmp(data[mid].name, key) < 0)
		return binary_search(data, key, mid + 1, high);
	else
		return binary_search(data, key, low, mid - 1);
}