#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char word[1000001], alpha[2][26], c;
	int count[26] = { 0 }, len, bigIdx = 0, isOverlap = 0;

	//! 단어를 입력받고, alpha에 대/소문자 알파벳을 순서대로 넣는 작업
	scanf("%s", word);
	for (len = 0; word[len] != '\0'; len++);
	for (int i = 0; i < 26; i++) {
		alpha[0][i] = 'A' + i;
		alpha[1][i] = 'a' + i;
	}
	//! 단어에 들어간 알파벳 개수 세기
	for (int i = 0; i < len; i++) {
		c = word[i];
		for (int j = 0; j < 26; j++)
			if ((c == alpha[0][j]) || (c == alpha[1][j])) {
				count[j]++;
				break;
			}
	}
	//! 등장한 알파벳 개수 중 가장 많이 등장한 인덱스 번호 구하기
	for (int i = 1; i < 26; i++)
		if (count[i] >= count[bigIdx])
			bigIdx = i;
	//! 중복되는 개수가 있는지 확인하기
	for (int i = 0; i < bigIdx; i++)
		if (count[i] == count[bigIdx]) {
			isOverlap = 1;
			break;
		}

	if (isOverlap)
		printf("?");
	else
		printf("%c", alpha[0][bigIdx]);

	return 0;
}