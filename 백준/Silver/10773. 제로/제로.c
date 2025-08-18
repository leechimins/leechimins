#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int K, n[100000] = { 0 }, total = 0, number, index = 0;
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &number);
		if (number == 0)
			n[--index] = 0;
		else
			n[index++] = number;
	}

	for (int i = 0; i < index; i++)
		total += n[i];

	printf("%d", total);

	return 0;
}