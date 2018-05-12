#include "matches.h"
#include <time.h>

int check_turn()
{
	int check;
	scanw("%d", &check);

	if (check == 1 && check != '-') {
		return 1;
	} else if (check == 2 && check != '-') {
		return 2;
	} else {
		clear();
		attron(COLOR_PAIR(2));
		printw("You entered an invalid value, please try again: ");
		attron(COLOR_PAIR(3));
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
	if (turn == 1) {
		return 2;
	} else {
		return 1;
	}
}

void strategy(int matches_remain, int first, int *buffer, int input, int *check_miscalculation)
{
	srand(time(NULL));
 	if (matches_remain >= 0) {
 		if (89 < matches_remain) {
 			if (first == 2) {
				if (input + *buffer < 11 && input != 0) {
					*buffer = 11 - (input + *buffer);
					*check_miscalculation = 1;
				} else {
 					*buffer = rand() % 10 + 1;
				}
 			} else {
 				*buffer = matches_remain - 89;
 			}
 		} else if (78 < matches_remain) {
 			if (first == 2) {
 				if (input + *buffer > 11 && *check_miscalculation == 0) {
  					*buffer = 22 - (input + *buffer);
					*check_miscalculation = 1;
 				} else if (*check_miscalculation == 1) {
					*buffer = matches_remain - 78;
				} else {
					*buffer = rand() % 10 + 1;;
				}
 			} else {
 				*buffer = matches_remain - 78;
 			}
 		} else if (67 < matches_remain) {
			if (first == 2) {
				if (input + *buffer < 11 && *check_miscalculation == 0) {
					*buffer = 11 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (input + *buffer > 11 && *check_miscalculation == 0) {
					*buffer = 22 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (*check_miscalculation == 1) {
					*buffer = matches_remain - 67;
				} else {
					*buffer = rand() % 10 + 1;;
				}
 			} else {
 				*buffer = matches_remain - 67;
 			}
 		} else if (56 < matches_remain) {
 			if (first == 2) {
				if (input + *buffer < 11 && *check_miscalculation == 0) {
					*buffer = 11 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (input + *buffer > 11 && *check_miscalculation == 0) {
					*buffer = 22 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (*check_miscalculation == 1) {
					*buffer = matches_remain - 56;
				} else {
					*buffer = rand() % 10 + 1;;
				}
 			} else {
 				*buffer = matches_remain - 56;
 			}
 		} else if (45 < matches_remain) {
 			if (first == 2) {
				if (input + *buffer < 11 && *check_miscalculation == 0) {
					*buffer = 11 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (input + *buffer > 11 && *check_miscalculation == 0) {
					*buffer = 22 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (*check_miscalculation == 1) {
					*buffer = matches_remain - 45;
				} else {
					*buffer = rand() % 10 + 1;;
				}
 			} else {
 				*buffer = matches_remain - 45;
 			}
 		} else if (34 < matches_remain) {
 			if (first == 2) {
				if (input + *buffer < 11 && *check_miscalculation == 0) {
					*buffer = 11 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (input + *buffer > 11 && *check_miscalculation == 0) {
					*buffer = 22 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (*check_miscalculation == 1) {
					*buffer = matches_remain - 34;
				} else {
					*buffer = rand() % 10 + 1;;
				}
 			} else {
 				*buffer = matches_remain - 34;
 			}
 		} else if (23 < matches_remain) {
 			if (first == 2) {
				if (input + *buffer < 11 && *check_miscalculation == 0) {
					*buffer = 11 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (input + *buffer > 11 && *check_miscalculation == 0) {
					*buffer = 22 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (*check_miscalculation == 1) {
					*buffer = matches_remain - 23;
				} else {
					*buffer = rand() % 10 + 1;;
				}
 			} else {
 				*buffer = matches_remain - 23;
 			}
 		} else if (12 < matches_remain) {
 			if (first == 2) {
				if (input + *buffer < 11 && *check_miscalculation == 0) {
					*buffer = 11 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (input + *buffer > 11 && *check_miscalculation == 0) {
					*buffer = 22 - (input + *buffer);
					*check_miscalculation = 1;
				} else if (*check_miscalculation == 1) {
					*buffer = matches_remain - 12;
				} else {
					*buffer = rand() % 10 + 1;;
				}
 			} else {
 				*buffer = matches_remain - 12;
 			}
 		} else if (0 < matches_remain) {
 			if (first == 2) {
				if (*check_miscalculation == 0) {
 					*buffer = rand() % 10 + 1;
				} else {
					*buffer = 11 - input;
				}
 			} else {
 				*buffer = 11 - input;
 			}
 		}
	}
}

int check_result(int turn, int matches_remain, int input)
{
	if (turn == 2 && matches_remain <= 10 && input < 9 && matches_remain > 2) {
		return 1;
	} else if (turn == 1 && matches_remain <= 0) {
		return 1;
	} else {
		return 0;
	}
}
