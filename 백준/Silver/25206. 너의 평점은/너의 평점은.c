#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

double change_rating2num(char[]);

int main(void) {
	char subject[51], rating[3];
	double ratingNum, credit, score, totalScore = 0, totalCredit = 0, totalRating;
	
	for (int _ = 0; _ < 20; _++) {
		scanf("%s %lf %s", subject, &credit, rating);

		if (strcmp(rating, "P") == 0)
			continue;

		ratingNum = change_rating2num(rating);
		score = ratingNum * credit;
		totalCredit += credit;
		totalScore += score;		
	}
	totalRating = totalScore / totalCredit;

	printf("%f", totalRating);

	return 0;
}
double change_rating2num(char r[]) {
	if (!strcmp(r, "A+"))
		return 4.5;
	else if (!strcmp(r, "A0"))
		return 4.0;
	else if (!strcmp(r, "B+"))
		return 3.5;
	else if (!strcmp(r, "B0"))
		return 3.0;
	else if (!strcmp(r, "C+"))
		return 2.5;
	else if (!strcmp(r, "C0"))
		return 2.0;
	else if (!strcmp(r, "D+"))
		return 1.5;
	else if (!strcmp(r, "D0"))
		return 1.0;
	else
		return 0;
}