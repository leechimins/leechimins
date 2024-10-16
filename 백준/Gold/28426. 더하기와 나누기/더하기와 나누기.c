#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    printf("2 ");
    for (int i = 1; i < n; i++)
        printf("%d ", i*4);
    
	return 0;
}