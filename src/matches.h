#ifndef MATCHES_H
#define MATCHES_H

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #define msleep(msec) Sleep(msec)
#else
    #include <unistd.h>
    #define msleep(msec) usleep(msec * 1000)
#endif

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int check_turn();
int turn_inversion(int turn);
int check_input(int ramain);
void strategy(int matches_remain, int first, int *buffer, int input, int *check_miscalculation);
int check_result(int turn, int matches_remain, int input);

#endif
