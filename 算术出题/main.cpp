#include <stdio.h>

#include <stdlib.h>

#include <iostream>

#include <fstream>

#include <time.h>

#include <windows.h>

#pragma warning(disable:4996)

using namespace std;

char operation(int operation);

float createEquation(FILE * ansfile, FILE * quefile);

float calculate(int number1, int number2, int operation);



const int jia = 1, subtract = 2, multiplication = 3, division = 4;

int main() {

	int num, i;

	float answer;

	printf("请输入题目个数:");

	scanf_s("%d", &num,5);

	srand(time(0));

	FILE * ansfile = fopen("Answers.txt","w");

	FILE * quefile = fopen("Questions.txt", "w");
	
	for (i = 0; i < num; i++) {

		createEquation(ansfile, quefile);
	}

	_fcloseall();

	system("pause");

	return 0;
}



float createEquation(FILE * ansfile, FILE * quefile) {

	int number1, number2, number3, operation1, operation2;

	float answer = 0;

	do {
		number1 = rand() % 100 + 1;

		number2 = rand() % 100 + 1;

		number3 = rand() % 100 + 1;

		operation1 = rand() % 4 + 1;

		operation2 = rand() % 4 + 1;

		if (operation1 == multiplication || operation1 == division) {

			answer = calculate(calculate(number1, number2, operation1), number3, operation2);

		}

		else {

			if (operation2 == multiplication || operation2 == division) {

				answer = calculate(number1, calculate(number2, number3, operation1), operation2);

			}

			else {

				answer = calculate(calculate(number1, number2, operation1), number3, operation2);

			}

		}

	} while (answer < 0);

	

	printf("%4d %c %4d %c %4d =\n", number1, operation(operation1), number2, operation(operation2), number3);

	fprintf_s(quefile, "%4d %c %4d %c %4d =\n", number1, operation(operation1), number2, operation(operation2), number3);

	fprintf_s(ansfile, "%8f\n", answer);

	return 0;
}



char operation(int operation) {

	char c;

	switch (operation) {

	case jia:

		c = '+';

		break;

	case subtract:

		c = '-';

		break;

	case multiplication:

		c = '*';

		break;

	case division:

		c = '/';

		break;

	}

	return c;

}



float calculate(int number1, int number2, int operation) {

	switch (operation) {

	case jia:

		return (float)number1 + number2;

	case subtract:

		return (float)number1 - number2;

	case multiplication:

		return (float)number1 * number2;

	case division:

		return (float)number1 / number2;

	}

}