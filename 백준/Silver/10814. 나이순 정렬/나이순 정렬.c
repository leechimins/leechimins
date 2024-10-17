#include <stdio.h>

#define SIZE 100000

int main(void) {
	int N, userAge, age[201][SIZE] = { 0 }, sameAge[201] = { 0 };
	char name[SIZE][101];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %s", &userAge, name[i]);
		age[userAge][sameAge[userAge]++] = i;
	}

	for (int i = 1; i <= 200; i++) {
		int j = 0;
		while (j < sameAge[i]) printf("%d %s\n", i, name[age[i][j++]]);
	}

	return 0;
}