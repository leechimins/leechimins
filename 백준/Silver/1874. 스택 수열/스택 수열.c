#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef int Element;
typedef struct {
    Element* data;
    int maxSize;
    int top;
} Stack;

void init_stack(Stack* s, int size);
void delete_stack(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
void display(Stack* s);
void push(Stack* s, Element item);
Element pop(Stack* s);
Element peek(Stack* s);

int main(void) {
    int n, flag = 1, i = 0, j = 0;
    scanf("%d", &n);

    Stack stack;
    init_stack(&stack, n);
    
    Element* answer = (Element*)malloc(sizeof(Element) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &answer[i]);

    int* result = (int*)malloc(sizeof(int) * 2 * n);
    Element num = 1;

    while (i < 2 * n) {

        if (num <= n) {
            push(&stack, num++);
            result[i++] = 1;
        }
        else {
            flag = 0;
            break;
        }

        while (peek(&stack) == answer[j]) {
            pop(&stack);
            result[i++] = 0;
            j++;
        }
    }

    if (flag && is_empty(&stack))
        for (int i = 0; i < 2 * n; i++)
            printf("%c\n", (result[i] ? '+' : '-'));
    else
        printf("NO");

    free(answer);
    free(result);
    delete_stack(&stack);
    return 0;
}

void init_stack(Stack* s, int size) {
    s->top = -1;
    s->maxSize = size;
    s->data = (Element*)malloc(sizeof(Element) * s->maxSize);
}

void delete_stack(Stack* s) {
    free(s->data);
}

int is_empty(Stack* s) { return (s->top == -1); }
int is_full(Stack* s) { return (s->top == (s->maxSize - 1)); }

void display(Stack* s) {
    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->data[i]);
    printf("\n");
}

void push(Stack* s, Element item) {
    if (is_full(s))
        return;
    s->top++;
    s->data[s->top] = item;
}

Element pop(Stack* s) {
    if (is_empty(s))
        return -1;
    return s->data[(s->top)--];
}

Element peek(Stack* s) {
    if (is_empty(s))
        return -1;
    return s->data[s->top];
}