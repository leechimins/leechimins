#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int element;  //! 요소의 자료형을 자유롭게 수정해 사용 가능
/*  ## 예시 ##
typedef struct {
    char name[20];
    int age;
    double height;
} element;
*/
typedef struct {
    element* data;
    int capacity;
    int top;
} Stack;

void init_stack(Stack* s, int size);
void delete(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
void push(Stack* s, element item);
element pop(Stack* s);
element peek(Stack* s);


int main(void) {
    Stack stack;
    init_stack(&stack, 5);
    element input = 0;

    peek(&stack);
    while (scanf("%d", &input), input) push(&stack, input);
    printf("%d\n", peek(&stack));
    while (!is_empty(&stack)) printf("%d ", pop(&stack));
    printf("%d ", pop(&stack));

    delete(&stack);

    return 0;
}

void init_stack(Stack* s, int size) {
    s->top = -1;
    s->capacity = size;
    s->data = (element*)malloc((s->capacity) * sizeof(element));
}

void delete(Stack* s) {
    printf("Stack data free\n");
    free(s->data);
}

int is_empty(Stack* s) { return (s->top == -1); }
int is_full(Stack* s) { return (s->top == (s->capacity - 1)); }

void push(Stack* s, element item) {
    if (is_full(s)) {
        // printf("Stack full\n");
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, (s->capacity) * sizeof(element));
    }
    s->data[++(s->top)] = item;
}
element pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack empty\n");
        return NULL;
    }
    return s->data[(s->top)--];
}
element peek(Stack* s) {
    if (is_empty(s)) {
        printf("Stack empty\n");
        return NULL;
    }
    else return s->data[s->top];
}
