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
	if (ramain >= 2 && ramain <= 10) {
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

void strategy(int matches_remain, int first, int *buffer)
{
 	if (matches_remain > 12) {
 		if (89 < matches_remain && matches_remain >= 78) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 				//return buffer;
 			} else {
 				*buffer = matches_remain - 89;
 				//return buffer;
 			}
 		} else if (78 < matches_remain && matches_remain >= 78) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 				//return buffer;
 			} else {	
 				*buffer = matches_remain - 78;
 				//return buffer;
 			}
 		} else if (67 < matches_remain && matches_remain >= 67) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 				//return buffer;
 			} else {
 				*buffer = matches_remain - 67;
 				//return buffer;
 			}
 		} else if (56 < matches_remain && matches_remain >= 56) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 				//return buffer;
 			} else {
 				*buffer = matches_remain - 56;
 				//return buffer;
 			}
 		} else if (45 < matches_remain && matches_remain >= 45) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 				//return buffer;
 			} else {
 				*buffer = matches_remain - 45;
 				//return buffer;
 			}
 		} else if (34 < matches_remain && matches_remain >= 34) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 				//return buffer;
 			} else {
 				*buffer = matches_remain - 34;
 				//return buffer;
 			}
 		} else if (23 < matches_remain && matches_remain >= 23) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 				//return buffer;
 			} else {
 				*buffer = matches_remain - 23;
 				//return buffer;
 			}
 		} else if (12 < matches_remain && matches_remain >= 12) {
 			if (first == 2) {
 				*buffer = rand() % 10 + 1;
 				//return buffer;
 			} else {
 				*buffer = matches_remain - 12;
 				//return buffer;
 			}
 		}	
    } else if (matches_remain <= 10) {
  		*buffer = matches_remain - 1;
  		//return buffer;
    }
}