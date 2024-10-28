#include <stdio.h>
#define SIZE 21

int cmdToNum(char cmd[]);
void add(int x, int set[]);
void removeSet(int x, int set[]);
int check(int x, int set[]);
void toggle(int x, int set[]);
void all(int set[]);
void empty(int set[]);

int main(void) {
	int N, cmdNum, x, set[SIZE] = { SIZE };
	char cmd[10];
	scanf("%d", &N);

	while (N--) {
		scanf("%s", cmd); cmdNum = cmdToNum(cmd);

		switch (cmdNum) {
		case 1: case 2: case 3: case 4: scanf("%d", &x); break;
		default: break;
		}

		switch (cmdNum) {
		case 1: add(x, set); break;
		case 2: removeSet(x, set); break;
		case 3: check(x, set); break;
		case 4: toggle(x, set); break;
		case 5: all(set); break;
		case 6: empty(set); break;
		default: printf("오류\n"); break;
		}
	}
	return 0;
}

int cmdToNum(char cmd[]) {
	switch (cmd[0]) {
	case 'a':
		if (cmd[1] == 'd') return 1;
		else return 5;
	case 'r': return 2;
	case 'c': return 3;
	case't': return 4;
	case 'e': return 6;
	default: return 0;
	}
}
void add(int x, int set[]) {
	set[x] = 1;
}
void removeSet(int x, int set[]) {
	set[x] = 0;
}
int check(int x, int set[]) {
	if (set[x]) { printf("1\n"); return 1; }
	else { printf("0\n"); return 0; }
}
void toggle(int x, int set[]) {
	set[x] = !set[x];
}
void all(int set[]) {
	for (int i = 1; i < set[0]; i++) set[i] = 1;
}
void empty(int set[]) {
	for (int i = 1; i < set[0]; i++) set[i] = 0;
}