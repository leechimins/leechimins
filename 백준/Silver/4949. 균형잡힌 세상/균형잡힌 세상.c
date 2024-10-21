#include <stdio.h>
#define LEN 102

int returnP(char word[LEN], char ps[LEN]);
int VPS(char ps[LEN], int len);

int main(void) {
	int len, ans;
	char str[LEN], ps[LEN];

	while (gets(str), str[0] != '.') {
		len = returnP(str, ps);
		if (VPS(ps, len)) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}

int returnP(char word[LEN], char ps[LEN]) {
	int i = 0, len = 0;

	while (word[i] != '.')
		switch (word[i]) {
		case '(':
		case ')':
		case '[':
		case ']':
			ps[len] = word[i];
			len++;
		default:
			i++;
			break;
		}
	ps[len] = '\0';
	return len;
}

int VPS(char ps[LEN], int len) {
	int i, top;
	char stack[LEN] = { 0 };
	for (i = 0, top = 0; i < len; i++) {
		if (ps[i] == '(' || ps[i] == '[') stack[++top] = ps[i];
		else if ((ps[i] == ')' && stack[top] == '(') || ps[i] == ']' && stack[top] == '[') stack[top--] = 0;
		else return 0;
	}
	if (top) return 0;
	else return 1;
}