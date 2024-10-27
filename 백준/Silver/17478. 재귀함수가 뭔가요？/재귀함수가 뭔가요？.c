#include <stdio.h>

void recur(int size, int n);
void printStory(int n);
void printEnd(int n);
void printDesh(int n);

int main(void) {
	int count;
	scanf("%d", &count);
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	recur(count + 1, count + 1);

	return 0;
}

void recur(int size, int n) {
	if (n == 1) {
		printDesh(size - n);
		printf("\"재귀함수가 뭔가요?\"\n");
		printDesh(size - n);
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
		printEnd(size - n);
		return;
	}
	printStory(size - n);
	recur(size, n - 1);
	printEnd(size - n);
}
void printStory(int n) {
	printDesh(n); printf("\"재귀함수가 뭔가요?\"\n");
	printDesh(n); printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
	printDesh(n); printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
	printDesh(n); printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
}
void printEnd(int n) {
	printDesh(n); printf("라고 답변하였지.\n");
}
void printDesh(int n) {
	for (int i = 0; i < n*4; i++) printf("_");
}