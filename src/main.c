#include "matches.h"

int main()
{
	printf("Приветствую в игре 100 спичек, я робот, который будет против тебя играть! Выбери каким ты хочешь ходить: ");
	int turn = check_turn();

	int input, stroke_check, matches_remain = 100, buffer, comp;

	while (matches_remain >= 0 && matches_remain < 101 
			&& matches_remain != 2 && matches_remain != 0) {
		if (turn == 2) {
			turn = turn_inversion(turn);

			if (matches_remain == 12) {
				buffer = 10;
			} else if (matches_remain == 11) {
				buffer = 9;
			} else if (matches_remain == 10) {
				buffer = 8;
			} else if (matches_remain == 9) {
				buffer = 7;
			} else if (matches_remain == 8) {
				buffer = 6;
			} else if (matches_remain == 7) {
				buffer = 5;
			} else if (matches_remain == 6) {
				buffer = 4;
			} else if (matches_remain == 5) {
				buffer = 3;
			} else if (matches_remain == 4) {
				buffer = 2;
			} else if (matches_remain == 3) {
				buffer = 1;
			}

			if (matches_remain > 13) {
			if (matches_remain % 2 == 0 && comp % 2 == 0) {
				buffer = 11 - comp;
			} else if (matches_remain % 2 == 0 && comp % 2 == 1) {
				buffer = 10 - comp;
			} else if (matches_remain % 2 == 1 && comp % 2 == 1) {
				buffer = 11 - comp;
			} else if (matches_remain % 2 == 1 && comp % 2 == 0) {
				buffer = 10 - comp;
			}
			}
			matches_remain = matches_remain - buffer;
			printf("Я взял %d сталось %d. Твой ход!\n", buffer, matches_remain);
		} else {
			turn = turn_inversion(turn);
			scanf("%d", &input);
			comp = input;
			stroke_check = check_input(input);
			if (stroke_check == 1) {
				matches_remain = matches_remain - input;
				printf("Осталось %d\n", matches_remain);
			} else {
				turn = turn_inversion(turn);
				printf("Вы ввели неверное значение, пожалуйста, повторите попытку: ");
			}
		}
	}

	if (turn == 2 && (matches_remain == 2 || matches_remain == 1
			|| matches_remain == 0)) {
		printf("Вы выиграли!\n");
	} else if (turn == 2) {
		printf("Вы выиграли!\n");
	} else {
		printf("Вы проиграли!\n");
	}

	return 0;
}