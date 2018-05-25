#ifndef MATCHES_H
#define MATCHES_H

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #define msleep(msec) Sleep(msec)
#else
    #include <unistd.h>
    #define msleep(msec) usleep(msec * 1000)
#endif

int check_turn();
int turn_inversion(int turn);
int check_input(int ramain);
void strategy(int matches_remain, int first, int *buffer, int input, int *check_miscalculation);
int check_result(int turn, int matches_remain, int input, int fl_result);
void strategy_move(int matches_remain, int first, int *buffer, int input, int *check_miscalculation, int rang);
void loked_result(int turn, int matches_remain, int input, int fl_result, int col, int row, const char *won, const char *lose, const char *over);

#endif
