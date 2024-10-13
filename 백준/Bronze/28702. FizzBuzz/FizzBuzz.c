#include <stdio.h>

int StN(char word[]);
void FizzBuzz(int num);

int main(void) {
	int num;
	char input[3][9];
	for (int i = 0; i < 3; i++) scanf("%s", input[i]);

	if (StN(input[0])) num = StN(input[0]) + 3;
	else if (StN(input[1])) num = StN(input[1]) + 2;
	else num = StN(input[2]) + 1;

	FizzBuzz(num);

	return 0;
}

int StN(char word[]) {
	int num = 0, len = 0;
	while (word[++len] != '\0');

	for (int i = 0; i < len; i++)
		if ('0' <= word[i] && word[i] <= '9') {
			num = num * 10 + word[i] - '0';
		}
		else return 0;
	return num;
}
void FizzBuzz(int num) {
	if (num % 15 == 0) printf("FizzBuzz");
	else if (num % 3 == 0) printf("Fizz");
	else if (num % 5 == 0) printf("Buzz");
	else printf("%d", num);
}