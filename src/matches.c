#include "matches.h"
#include <time.h>
//#include "name.h"

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
		//mvwprintw(stdscr, 2, (getmaxx(stdscr) - strlen(entered)) / 2, entered);
		printw("Error, please try again: ");
		attron(COLOR_PAIR(3));
		return check_turn();
		clear();
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
 			strategy_move(matches_remain, first, buffer, input, check_miscalculation, 78);
 		} else if (67 < matches_remain) {
			strategy_move(matches_remain, first, buffer, input, check_miscalculation, 67);
 		} else if (56 < matches_remain) {
 			strategy_move(matches_remain, first, buffer, input, check_miscalculation, 56);
 		} else if (45 < matches_remain) {
			strategy_move(matches_remain, first, buffer, input, check_miscalculation, 45);
 		} else if (34 < matches_remain) {
			strategy_move(matches_remain, first, buffer, input, check_miscalculation, 34);
 		} else if (23 < matches_remain) {
			strategy_move(matches_remain, first, buffer, input, check_miscalculation, 23);
 		} else if (12 < matches_remain) {
 			strategy_move(matches_remain, first, buffer, input, check_miscalculation, 12);
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

void strategy_move(int matches_remain, int first, int *buffer, int input, int *check_miscalculation, int rang) 
{
	if (rang < matches_remain) {
 		if (first == 2) {
			if (input + *buffer < 11 && *check_miscalculation == 0) {
				*buffer = 11 - (input + *buffer);
				*check_miscalculation = 1;
			} else if (input + *buffer > 11 && *check_miscalculation == 0) {
				*buffer = 22 - (input + *buffer);
				*check_miscalculation = 1;
			} else if (*check_miscalculation == 1) {
				*buffer = matches_remain - rang;
			} else {
				*buffer = rand() % 10 + 1;;
			}
		} else {
 			*buffer = matches_remain - rang;
 		}
	}
}

int check_result(int turn, int matches_remain, int input, int fl)
{
	if (turn == 2 && matches_remain <= 10 && input < 9 && matches_remain > 2 && fl == 1) {
		return 1;
	} else if (turn == 1 && matches_remain <= 0 && fl == 1) {
		return 1;
	} else if (fl == 0) {
		return 3;
	} else {
		return 0;
	}
}

void loked_result(int turn, int matches_remain, int input, int fl, int col, int row, const char *won, const char *lose, const char *over) 
{
	while (true) {
		if (check_result(turn, matches_remain, input, fl) == 1) {
			for (col = (getmaxx(stdscr) - strlen(won)); col != 0; col--) {
				clear();
				attron(COLOR_PAIR(1));	
				mvaddstr(row / 2, col, won);
				refresh();
				msleep(130);
			}
		} else if (check_result(turn, matches_remain, input, fl) == 3){
			for (col = (getmaxx(stdscr) - strlen(over)); col != 0; col--) {
				clear();
				attron(COLOR_PAIR(4));	
				mvaddstr(row / 2, col, over);
				refresh();
				msleep(130);
			}
		} else {
			for (col = (getmaxx(stdscr) - strlen(lose)); col != 0; col--) {
				clear();
				attron(COLOR_PAIR(4));	
				mvaddstr(row / 2, col, lose);
				refresh();
				msleep(130);
			}	
		}
	}
}