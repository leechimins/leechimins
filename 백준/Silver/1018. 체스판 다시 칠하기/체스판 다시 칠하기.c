#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char board[51][51];
	int n, m;
	char start;
	int r, c, count, min = 32;
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);

	for (int col = 0; col <= m - 8; col++)
		for (int row = 0; row <= n - 8; row++) {
			start = board[row][col];
			count = 0;
			for (r = row; r < row + 8; r++)
				for (c = col; c < col + 8; c++)
					if ((r % 2 && c % 2) || (r % 2 ==0 && c % 2==0)) {
						if (board[r][c] != start) count++;
					}
					else {
						if (board[r][c] == start) count++;
					}
			count = count > 32 ? 64 - count : count;
			min = count < min ? count : min;
		}
	printf("%d", min);

	return 0;
}