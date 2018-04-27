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

/*
int check_input(int ramain)
{
	if (ramain >= 2 && ramain <= 10) {
		recheck 1;
	} else {
		recheck 0;
	}
}
*/