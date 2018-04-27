#include "matches.h"

int main()
{
	printf("Приветствую в игре 100 спичек, я робот, который будет против тебя играть! Выбери каким ты хочешь ходить: ");
	int turn = check_turn();

	int input, stroke_check, matches_remain = 100, remainder;

	while (matches_remain < 100 && matches_remain != 2 && matches_remain != 0) {
		if (turn == 2) {
			turn = check_turn_inversion(turn);
			// Для компа
		} else {
			turn = check_turn_inversion(turn);
			// Для чела
		}
	}

	if(turn == 2) {
		printf("Вы проиграли!");
	} else {
		printf("Вы выиграл!");
	}

	return 0;
}
/*
В правильности работы не уверен, нужно дописать код позже.
[НАПОМИНАНИЕ] Работает по принципу качелей. Похожий трюк реализовывал, когда писал шахматы(Почему качелей, наверное, пойму только я, надо будет, сприсишь))
*/