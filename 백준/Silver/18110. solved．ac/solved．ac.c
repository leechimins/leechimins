#include <stdio.h>

void trim(int amount, int arr[], int upDown);

int main(void) {
	int N, out, vote, score = 0, arr[31] = { 0 };
	scanf("%d", &N);

	if (N == 0) { printf("0"); return 0; }

	for (int i = 0; i < N; i++) { scanf("%d", &vote); arr[vote]++; }

	out = (N * 15 + 100 / 2) / 100;
	trim(out, arr, 1);
	trim(out, arr, -1);
	for (int i = 1; i < 31; i++) score += arr[i] * i;
	score = (score + (N - 2 * out) / 2) / (N - 2 * out);
	printf("%d", score);

	return 0;
}

void trim(int amount, int arr[], int upDown) {
	for (int i = upDown > 0 ? 1 : 30; amount > 0; amount--) {
		while (arr[i] == 0) i += upDown;
		arr[i]--;
	}
}