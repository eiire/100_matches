#ifndef MATCHES_H
#define MATCHES_H

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int row, col;
const char *hello = "Welcome to the game 100 matches!";
const char *robot = "I am a robot that will be against you";
const char *choice = "Choose how you want to go: ";
const char *won = "You won!";
const char *lose = "You lose!";
int check_turn();
int turn_inversion(int turn);
int check_input(int ramain);
void strategy(int matches_remain, int first, int *buffer);

#endif
