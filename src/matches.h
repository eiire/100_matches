#ifndef MATCHES_H
#define MATCHES_H

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int check_turn();
int turn_inversion(int turn);
int check_input(int ramain);
void strategy(int matches_remain, int first, int *buffer, int input, int *check_miscalculation);
int check_result(int turn, int matches_remain, int input, int fl);
void strategy_move(int matches_remain, int first, int *buffer, int input, int *check_miscalculation, int rang);

#endif
