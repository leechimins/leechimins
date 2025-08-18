#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char kind[21];
	int count;
} Type;

int main(void) {
	int TC, n, top, result, temp;
	char name[30][21], kind[30][21];
	Type type[30];
	scanf("%d", &TC);

	while (TC--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s %s", name[i], kind[i]);

		top = 0;
		for (int i = 0, j; i < n; i++) {
			j = 0;
			while (j < top) {
				if (strcmp(type[j].kind, kind[i]) == 0) {
					type[j].count++;
					break;
				}
				j++;
			}
			if (j >= top) {
				strcpy(type[top].kind, kind[i]);
				type[top++].count = 1;
			}
		}

		/*for (int i = 0; i < top; i++)
			printf("%d %s\n", type[i].count, type[i].kind);*/

		result = 1;
		for (int i = 0; i < top; i++)
			result *= type[i].count + 1;

		result--;
		printf("%d\n", result);
	}

	return 0;
}