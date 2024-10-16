#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int paper[100][100] = { 0 };
	int count, x, y, area = 0;
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%d %d", &x, &y);

		for (int a = x; a < x + 10; a++)
			for (int b = y; b < y + 10; b++)
				paper[a][b] = 1;
	}
	for (x = 0; x < 100; x++)
		for (y = 0; y < 100; y++)
			if (paper[x][y])
				area++;

	printf("%d", area);

	return 0;
}