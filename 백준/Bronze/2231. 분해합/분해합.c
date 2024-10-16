#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, m, tmp, dssmbSum;
	scanf("%d", &n);

	for (m = n - 54; m < n; m++) {
		tmp = m;
		for (dssmbSum = tmp; tmp; tmp /= 10)
			dssmbSum += tmp % 10;
		if (dssmbSum == n) {
			printf("%d", m);
			return 0;
		}
	}
	printf("0");

	return 0;
}