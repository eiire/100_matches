#ifndef MATCHES_H
#define MATCHES_H

#include <stdio.h>
#include <stdlib.h>

int check_turn();
int turn_inversion(int turn);
int check_input(int ramain);
void strategy(int matches_remain, int first, int *buffer);

#endif