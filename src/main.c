#include "matches.h"
#include "name.h"

int main()
{

	int stroka = 0;

	initscr();

	getmaxyx(stdscr,int row,int col);

	curs_set(0);
	echo();

	mvwprintw(stdscr, stroka = stroka + 3 , (col - strlen(hello)) / 2, "%s", hello);
	mvwprintw(stdscr, stroka = stroka + 3 , (col - strlen(robot)) / 2, "%s", robot);
	mvwprintw(stdscr, row / 2 , (col - strlen(choice)) / 2 , "%s", choice);

	int turn = check_turn();
	int first = turn;
	clear();
	int input, stroke_check, matches_remain = 100, buffer;

	while (matches_remain >= 0 && matches_remain < 101
			&& matches_remain != 2 && matches_remain != 0) {
		if (turn == 2) {
			turn = turn_inversion(turn);
			strategy(matches_remain, first, &buffer);
			matches_remain = matches_remain - buffer;
			if (matches_remain >= 96)
				stroka = -1;
			mvwprintw(stdscr, stroka = stroka + 1 , (col - strlen(left)) / 2 - 30, "%s", took);
			mvwprintw(stdscr, stroka , (col - strlen(left)) / 2 - 22, "%d", buffer);
			mvwprintw(stdscr, stroka , (col - strlen(left)) / 2 , "%s", left);
			mvwprintw(stdscr, stroka , ((col - strlen(left)) / 2 + strlen(left) + 1) , "%d", matches_remain);
			mvwprintw(stdscr, stroka , ((col - strlen(ymove)) / 2) + 30 , "%s", ymove);
		} else {
			turn = turn_inversion(turn);
			if (matches_remain == 100)
				mvwprintw(stdscr, stroka = 0 , (col - strlen(nunb)) / 2 , "%s", nunb);
			scanw("%d", &input);
			stroke_check = check_input(input);
			if (stroke_check == 1) {
				matches_remain = matches_remain - input;
				mvwprintw(stdscr, stroka = stroka + 1 , (col - strlen(left)) / 2, "%s", left);
				mvwprintw(stdscr, stroka , (col - strlen(left)) / 2 + strlen(left) + 1, "%d", matches_remain);
			} else {
				turn = turn_inversion(turn);
				printw("You entered an invalid value, please try again: ");
				stroka = stroka + 1;
			}
		}
	}
while (true) {
	for ( col = (getmaxx(stdscr) - strlen(lose)) ; col != 0 ; col-- ) {
		clear();

	if (turn == 2 && (matches_remain == 2 || matches_remain == 1
			|| matches_remain == 0)) {
		mvaddstr(row / 2, col , won);
	} else if (turn == 1 && matches_remain < 0) {
		mvaddstr(row / 2, col , lose);
	} else {
		mvaddstr(row / 2, col , lose);
	}
		refresh();
            	msleep(100);
	}
}
		getch();
   	endwin();

	return 0;
}
