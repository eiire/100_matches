#include "matches.h"

int main()
{
	printf("Приветствую в игре 100 спичек, я робот, который будет против тебя играть! Выбери каким ты хочешь ходить: ");
	int turn = check_turn();

	int input, stroke_check, matches_remain = 100, buffer;

	while (matches_remain < 101 && matches_remain != 2 && matches_remain != 0) {
		if (turn == 2) {
			turn = turn_inversion(turn);
			buffer = rand() % 10;
			matches_remain = matches_remain - buffer;
			printf("Я взял %d сталось %d. Твой ход!\n", buffer, matches_remain);
		} else {
			turn = turn_inversion(turn);
			scanf("%d", &buffer);
			matches_remain = matches_remain - buffer;
			printf("Осталось %d\n", matches_remain);
		}
	}

	if (turn == 2) {
		printf("Вы проиграли!\n");
	} else {
		printf("Вы выиграли!\n");
	}

	return 0;
}