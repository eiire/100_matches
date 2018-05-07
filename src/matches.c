#include "matches.h"

int check_turn()
{
	int check;
	scanf("%d", &check);

	if (check == 1) {
		return 1;
	} else if (check == 2) {
		return 2;
	} else {
		printf("Введено неверное значение, пожалуйста, повторите попытку: ");
		return check_turn();
	}
}

int check_input(int ramain)
{
	if (ramain >= 1 && ramain <= 10) {
		return 1;
	} else {
		return 0;
	}
}

int turn_inversion(int turn)
{
	if(turn == 1) {
		return 2;
	} else {
		return 1;
	}
}

void strategy(int matches_remain, int first, int *buffer, int input)
{
 	if (matches_remain >= 12) {
 		if (89 < matches_remain) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 			} else {
 				*buffer = matches_remain - 89;
 			}
 		} else if (78 < matches_remain) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 			} else {	
 				*buffer = matches_remain - 78;
 			}
 		} else if (67 < matches_remain) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 			} else {
 				*buffer = matches_remain - 67;
 			}
 		} else if (56 < matches_remain) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 			} else {
 				*buffer = matches_remain - 56;
 			}
 		} else if (45 < matches_remain) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 			} else {
 				*buffer = matches_remain - 45;
 			}
 		} else if (34 < matches_remain) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 			} else {
 				*buffer = matches_remain - 34;
 			}
 		} else if (23 < matches_remain) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 			} else {
 				*buffer = matches_remain - 23;
 			}
 		} else if (12 < matches_remain) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 			} else {
 				*buffer = matches_remain - 12;
 			}
 		}
 	} else if (matches_remain < 12) {
 		if (first == 2) {
 			*buffer = rand() % 10 + 1;
 		} else {
 			*buffer = 11 - input;
 		}
 	}
}

void check_result(int turn, int matches_remain, int input)
{
	if (turn == 2 && matches_remain <= 10 && input < 9 && matches_remain > 2) {
		printf("Вы выиграли!\n");
	} else if (turn == 1 && matches_remain < 0) {
		printf("Вы проиграли!\n");
	} else {
		printf("Вы проиграли!\n");
	}
}