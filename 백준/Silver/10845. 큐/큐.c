#include <stdio.h>
#define SIZE 100002

int cmdToNum(char cmd[]);
void push(int x, int queue[]);
int pop(int queue[]);
int size(int queue[]);
int empty(int queue[]);
int front(int queue[]);
int back(int queue[]);

int main(void) {
	int N, cmdNum, x, queue[SIZE] = { 1, 1 };
	char command[6];
	scanf("%d", &N);
	while (N--) {
		scanf("%s", command);
		cmdNum = cmdToNum(command);
		switch (cmdNum)
		{
		case 1: scanf("%d", &x); push(x, queue); break;
		case 2: printf("%d\n", pop(queue)); break;
		case 3: printf("%d\n", size(queue)); break;
		case 4: printf("%d\n", empty(queue)); break;
		case 5: printf("%d\n", front(queue)); break;
		case 6: printf("%d\n", back(queue)); break;
		default: printf("오류\n"); break;
		}
	}

	return 0;
}

int cmdToNum(char cmd[]) {
	switch (cmd[0])
	{
	case 'p':
		if (cmd[1] == 'u') return 1;
		else return 2;
	case 's': return 3;
	case 'e': return 4;
	case'f': return 5;
	case 'b': return 6;
	default: return 0;
	}
}

//! queue[0] : 시작, queue[1] : 끝
void push(int x, int queue[]) {
	queue[1]++;
	queue[queue[1]] = x;
}
int pop(int queue[]) {
	if (back(queue) == -1) return -1;
	else {
		queue[0]++;
		int num = queue[queue[0]];
		queue[queue[0]] = 0;
		return num;
	}
}
int size(int queue[]) {
	return queue[1] - queue[0];
}
int empty(int queue[]) {
	if (queue[1] > queue[0]) return 0;
	else return 1;
}
int front(int queue[]) {
	if (empty(queue)) return -1;
	else return queue[queue[0]+1];
}
int back(int queue[]) {
	if (empty(queue)) return -1;
	else return queue[queue[1]];
}