#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int StN(char word[]);
int FizzBuzz(int num);

int main(void) {
	int num[3], flag;
	char input[3][9];
	for (int i = 0; i < 3; i++) {
		scanf("%s", input[i]);
	}

	if (StN(input[0])) {
		num[0] = StN(input[0]);
		num[1] = num[0] + 1;
		num[2] = num[0] + 2;
	}
	else if (StN(input[1])) {
		num[1] = StN(input[1]);
		num[0] = num[1] - 1;
		num[2] = num[1] + 1;
	}
	else {
		num[2] = StN(input[2]);
		num[1] = num[2] - 1;
		num[0] = num[2] - 2;
	}

	flag = FizzBuzz(num[2] + 1);
	if (flag == -1) printf("FizzBuzz");
	else if (flag == -2) printf("Fizz");
	else if (flag == -3) printf("Buzz");
	else printf("%d", flag);

	return 0;
}

int StN(char word[]) {
	int num = 0, len = 0;
	while (word[++len] != '\0');

	for (int i = 0; i < len; i++)
		if ('0' <= word[i] && word[i] <= '9') {
			num *= 10;
			num += word[i] - '0';
		}
		else return 0;
	return num;
}
int FizzBuzz(int num) {
	if (num % 3 == 0 && num % 5 == 0) return -1;
	else if (num % 3 == 0) return -2;
	else if (num % 5 == 0) return -3;
	else return num;
}