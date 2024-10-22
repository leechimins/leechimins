#include <stdio.h>
#define SIZE 100001

int cmdToNum(char cmd[]);
void push(int x, int stack[]);
int pop(int stack[]);
int size(int stack[]);
int empty(int stack[]);
int top(int stack[]);

int main(void) {
	int N, cmdNum, x, stack[SIZE] = { 0 };
	char command[6];
	scanf("%d", &N);
	while (N--) {
		scanf("%s", command);
		cmdNum = cmdToNum(command);
		if (cmdNum == 1) {
			scanf("%d", &x);
			push(x, stack);
		}
		else if (cmdNum == 2) printf("%d\n", pop(stack));
		else if (cmdNum == 3) printf("%d\n", size(stack));
		else if (cmdNum == 4) printf("%d\n", empty(stack));
		else if (cmdNum == 5) printf("%d\n", top(stack));
		else printf("오류\n");
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
	case't': return 5;
	default: return 0;
	}
}
void push(int x, int stack[]) {
	stack[0]++;
	stack[stack[0]] = x;
}
int pop(int stack[]) {
	if (top(stack) == -1) return -1;
	else {
		int num = stack[stack[0]];
		stack[stack[0]] = 0;
		stack[0]--;
		return num;
	}
}
int size(int stack[]) {
	return stack[0];
}
int empty(int stack[]) {
	if (stack[0] > 0) return 0;
	else return 1;
}
int top(int stack[]) {
	if (empty(stack)) return -1;
	else return stack[stack[0]];
}