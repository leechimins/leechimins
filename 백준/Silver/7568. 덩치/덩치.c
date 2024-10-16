#include <stdio.h>

int compare(int a1, int a2, int b1, int b2);

int main(void) {
	int N, x[50], y[50], rank[50];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		rank[i] = N;
		scanf("%d %d", &x[i], &y[i]);
	}

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			int flag = compare(x[i], y[i], x[j], y[j]);
			if (flag == 1) rank[i]--;
			else if (flag == -1) rank[j]--;
			else {
				rank[i]--;
				rank[j]--;
			}
		}

	for (int i = 0; i < N; i++) printf("%d ", rank[i]);

	return 0;
}

int compare(int a1, int a2, int b1, int b2) {
	if (a1 > b1 && a2 > b2) return 1;
	else if (a1 < b1 && a2 < b2) return -1;
	else return 0;
}