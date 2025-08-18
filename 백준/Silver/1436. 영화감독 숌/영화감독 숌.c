#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int in666(int n);

int main(void) {
	int n, num = 665;
	scanf("%d", &n);

	while (n) {
		if (in666(++num))
			n--;
	}

	printf("%d", num);

	return 0;
}

int in666(int n) {
	char num[50001], ans[] = "666";
	sprintf(num, "%d", n);
	if (strstr(num, ans))
		return 1;
	return 0;
}