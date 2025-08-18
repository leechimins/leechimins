#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, min = 2000, three = 0, five = 0, flag = 0;
	scanf("%d", &n);

	for (five = n / 5; five >= 0; five--) {
		three = (n - five * 5) / 3;
		if (five * 5 + three * 3 == n) {
			flag = 1;
			min = five + three < min ? five + three : min;
			break;
		}
	}

	if (flag)
		printf("%d", min);
	else
		printf("-1");

	return 0;
}