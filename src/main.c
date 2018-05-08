#include "matches.h"

int main()
{
	printf("Приветствую в игре 100 спичек, я робот, который будет против тебя играть! Выбери каким ты хочешь ходить: ");
	int turn = check_turn();
	int first = turn;

	int input = 0, stroke_check, matches_remain = 100, buffer = 0, oshibka = 0;

	while (matches_remain > 0 && matches_remain < 101) {
		if (turn == 2) {
			turn = turn_inversion(turn);
			strategy(matches_remain, first, &buffer, input, &oshibka);
			matches_remain = matches_remain - buffer;
			printf("Я взял %d сталось %d. Твой ход!\n", buffer, matches_remain);
		} else {
			turn = turn_inversion(turn);
			while (getchar() != '\n');
			scanf("%d", &input);
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

	check_result(turn, matches_remain, input);

	return 0;
}
