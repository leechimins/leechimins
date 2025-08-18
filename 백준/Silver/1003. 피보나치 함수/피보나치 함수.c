#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    int num;
    int zero, one;
} Element;

Element fibo(int n, Element* memo);
Element add_fibo(Element* e1, Element* e2);
void set_fibo(Element* e, int n, int z, int o);

int main(void) {
    Element memo[41];
    Element result;
    set_fibo(&memo[0], 0, 1, 0);
    set_fibo(&memo[1], 1, 0, 1);
    for (int i = 2; i <= 40; i++)
        set_fibo(&memo[i], -1, 0, 0);

    int T, N;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        result = fibo(N, memo);
        printf("%d %d\n", result.zero, result.one);
    }

    return 0;
}

void set_fibo(Element* e, int n, int z, int o) {
    e->num = n;
    e->zero = z;
    e->one = o;
}

Element add_fibo(Element* e1, Element* e2) {
    Element result;
    result.num = e1->num + e2->num;
    result.zero = e1->zero + e2->zero;
    result.one = e1->one + e2->one;
    return result;
}

Element fibo(int n, Element* memo) {
    if (n <= 1)
        return memo[n];

    if (memo[n].num == -1) {
        Element e1 = fibo(n - 1, memo);
        Element e2 = fibo(n - 2, memo);
        memo[n] = add_fibo(&e1, &e2);
    }

    return memo[n];
}