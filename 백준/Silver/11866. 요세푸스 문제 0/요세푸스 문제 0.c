#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct {
	int front;
	int rear;
	int maxSize;
	element* data;
} Queue;

void init_queue(Queue* q, int size);
void delete_queue(Queue* q);
int get_size(Queue* q);
int is_full(Queue* q);
int is_empty(Queue* q);
void enqueue(Queue* q, element item);
element dequeue(Queue* q);
element peek(Queue* q);

/* 예시
7 4 -> 4 1 6 5 7 3 2
7 6 -> 6 5 7 2 1 4 3
8 8 -> 8 1 3 6 5 2 7 4
7 8 -> 1 3 6 5 2 7 4
4 5 -> 1 3 4 2
*/

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	Queue q, temp;
	init_queue(&q, n);
	init_queue(&temp, k - 1);

	for (int i = 1; i <= n; i++)
		enqueue(&q, i);

	int size = n, turn = k;
	while (turn > size)
		turn -= size;
	for (int i = 1; i < turn; i++)
		enqueue(&temp, dequeue(&q));
	printf("<%d", dequeue(&q));
	for (int i = 1; i < turn; i++)
		enqueue(&q, dequeue(&temp));
	
	while (!is_empty(&q)) {
		size = get_size(&q);
		turn = k;
		while (turn > size)
			turn -= size;

		for (int i = 1; i < turn; i++)
			enqueue(&temp, dequeue(&q));
		printf(", %d", dequeue(&q));
		for (int i = 1; i < turn; i++)
			enqueue(&q, dequeue(&temp));
	}
	printf(">");

	delete_queue(&q);
	delete_queue(&temp);
	return 0;
}

void init_queue(Queue* q, int size) {
	q->front = 0;
	q->rear = 0;
	q->maxSize = size;
	q->data = (element*)malloc(sizeof(element) * q->maxSize);
}

void delete_queue(Queue* q) {
	free(q->data);
}

int get_size(Queue* q) {
	return (q->rear) - (q->front);
}

int is_full(Queue* q) { return ((q->rear + 1) == q->front); }
int is_empty(Queue* q) { return (q->front == q->rear); }

void enqueue(Queue* q, element item) {
	if (is_full(q)) printf("큐가 포화 상태입니다.");
	q->rear++;
	q->data[q->rear % q->maxSize] = item;
}

element dequeue(Queue* q) {
	if (is_empty(q)) printf("큐가 비어있습니다.");
	q->front++;

	return q->data[q->front % q->maxSize];
}

element peek(Queue* q) {
	if (is_empty(q)) printf("큐가 비어있습니다.");
	return q->data[(q->front + 1) % q->maxSize];
}