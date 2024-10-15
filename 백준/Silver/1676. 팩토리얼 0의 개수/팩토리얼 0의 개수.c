#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, ten = 0;
	scanf("%d", &N);

	for (; N >= 5; N /= 5) ten += N / 5;

	printf("%d", ten);

	return 0;
}