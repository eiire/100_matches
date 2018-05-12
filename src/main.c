#include "matches.h"
#include "name.h"

int main()
{
	int row, col, stroka = 0;

	initscr();

	getmaxyx(stdscr, row, col);

	curs_set(0);
	echo();
	start_color();
	init_pair(1,  COLOR_GREEN,    COLOR_BLACK);
	init_pair(2,  COLOR_RED,    COLOR_BLACK);
	init_pair(3,  COLOR_YELLOW,    COLOR_BLACK);
	attron(COLOR_PAIR(3));
	mvwprintw(stdscr, stroka = stroka + 3 , (col - strlen(hello)) / 2, "%s", hello);
	mvwprintw(stdscr, stroka = stroka + 3 , (col - strlen(robot)) / 2, "%s", robot);
	mvwprintw(stdscr, row / 2 , (col - strlen(choice)) / 2 , "%s", choice);

	int turn = check_turn();
	clear();
	int first = turn;
	int input = 0, stroke_check, matches_remain = 100, buffer = 0, check_miscalculation = 0;

	while (matches_remain > 0 && matches_remain < 101) {
		if (turn == 2) {
			turn = turn_inversion(turn);
			strategy(matches_remain, first, &buffer, input, &check_miscalculation);
			matches_remain = matches_remain - buffer;

			if (matches_remain > 89) {
				stroka = -1;
			}
			
			mvwprintw(stdscr, stroka = stroka + 1 , (col - strlen(left)) / 2 - 30, "%s", took);
			mvwprintw(stdscr, stroka , (col - strlen(left)) / 2 - 22, "%d", buffer);
			mvwprintw(stdscr, stroka , (col - strlen(left)) / 2 , "%s", left);
			mvwprintw(stdscr, stroka , ((col - strlen(left)) / 2 + strlen(left) + 1) , "%d", matches_remain);
			mvwprintw(stdscr, stroka , ((col - strlen(ymove)) / 2) + 30 , "%s", ymove);
		} else {
			turn = turn_inversion(turn);
			if (matches_remain == 100) {
				mvwprintw(stdscr, stroka = 0 , (col - strlen(nunb)) / 2 , "%s", nunb);
			}

			input = 0;
			scanw("%d", &input);
			stroke_check = check_input(input);

			if (stroke_check == 1) {
				matches_remain = matches_remain - input;
				mvwprintw(stdscr, stroka = stroka + 1 , (col - strlen(left)) / 2, "%s", left);
				mvwprintw(stdscr, stroka , (col - strlen(left)) / 2 + strlen(left) + 1, "%d", matches_remain);
			} else {
				turn = turn_inversion(turn);
				attron(COLOR_PAIR(2));
				printw("You entered an invalid value, please try again: ");
				attron(COLOR_PAIR(3));
				stroka = stroka + 1;
			}
		}
	}

	while (true) {
		for (col = (getmaxx(stdscr) - strlen(lose)); col != 0; col--) {
			clear();

			if (check_result(turn, matches_remain, input) == 1) {
				attron(COLOR_PAIR(1));				
				mvaddstr(row / 2, col , won);
			} else {
				attron(COLOR_PAIR(2));	
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
