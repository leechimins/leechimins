#include <stdio.h>

int main(void) {
	int N, two = 0, five = 0, ten = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int num = i;
		while ((num % 2) == 0) {
			num /= 2;
			two++;
		}
		while ((num % 5) == 0) {
			num /= 5;
			five++;
		}
	}
	while (two && five) {
		ten++; two--; five--;
	}

	printf("%d", ten);

	return 0;
}