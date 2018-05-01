#include "matches.h"

int main()
{
	printf("Приветствую в игре 100 спичек, я робот, который будет против тебя играть! Выбери каким ты хочешь ходить: ");
	int turn = check_turn();
	int first = turn;

	int input, stroke_check, matches_remain = 100, buffer;

	while (matches_remain >= 0 && matches_remain < 101 
			&& matches_remain != 2 && matches_remain != 0) {
		if (turn == 2) {
			turn = turn_inversion(turn);

			if (matches_remain > 12) {
				if (89 < matches_remain && matches_remain >= 78) {
					if (first == 2) {
						buffer = rand() % 10 + 1;
					} else {
						buffer = matches_remain - 89;
					}
				} else if (78 < matches_remain && matches_remain >= 78) {
					if (first == 2) {
						buffer = rand() % 10 + 1;
					} else {	
						buffer = matches_remain - 78;
					}
				} else if (67 < matches_remain && matches_remain >= 67) {
					if (first == 2) {
						buffer = rand() % 10 + 1;
					} else {
						buffer = matches_remain - 67;
					}
				} else if (56 < matches_remain && matches_remain >= 56) {
					if (first == 2) {
						buffer = rand() % 10 + 1;
					} else {
						buffer = matches_remain - 56;
					}
				} else if (45 < matches_remain && matches_remain >= 45) {
					if (first == 2) {
						buffer = rand() % 10 + 1;
					} else {
						buffer = matches_remain - 45;
					}
				} else if (34 < matches_remain && matches_remain >= 34) {
					if (first == 2) {
						buffer = rand() % 10 + 1;
					} else {
						buffer = matches_remain - 34;
					}
				} else if (23 < matches_remain && matches_remain >= 23) {
					if (first == 2) {
						buffer = rand() % 10 + 1;
					} else {
						buffer = matches_remain - 23;
					}
				} else if (12 < matches_remain && matches_remain >= 12) {
					if (first == 2) {
						buffer = rand() % 10 + 1;
					} else {
						buffer = matches_remain - 12;
					}
				}	
    		} else if (matches_remain <= 10) {
   		 		buffer = matches_remain - 1;
   		 	} else {
    	 		break;
    	 	}

			matches_remain = matches_remain - buffer;
			printf("Я взял %d сталось %d. Твой ход!\n", buffer, matches_remain);
		} else {
			turn = turn_inversion(turn);
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

	if (turn == 2 && (matches_remain == 2 || matches_remain == 1
			|| matches_remain == 0)) {
		printf("Вы выиграли!\n");
	} else if (turn == 1 && matches_remain < 0) {
		printf("Вы проиграли!\n");
	} else {
		printf("Вы проиграли!\n");
	}

	return 0;
}