#include <stdio.h>

int main(void) {
	int N, index;
	scanf("%d", &N);
	int number[10001] = { 0 };

	for (int i = 0; i < N; i++) {
		scanf("%d", &index);
		number[index]++;
	}

	for (int i = 1; i <= 10000; i++)
		while (number[i]--) printf("%d\n", i);
	
	return 0;
}