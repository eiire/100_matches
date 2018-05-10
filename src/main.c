#include "matches.h"
#include "name.h"

int main()
{

	int row, col, stroka = 0;

	initscr();

	getmaxyx(stdscr, row, col);

	curs_set(0);
	echo();

	mvwprintw(stdscr, stroka = stroka + 3 , (col - strlen(hello)) / 2, "%s", hello);
	mvwprintw(stdscr, stroka = stroka + 3 , (col - strlen(robot)) / 2, "%s", robot);
	mvwprintw(stdscr, row / 2 , (col - strlen(choice)) / 2 , "%s", choice);

	int turn = check_turn();
	int first = turn;

	int input = 0, stroke_check, matches_remain = 100, buffer = 0, check_miscalculation = 0;

	clear();

	while (matches_remain > 0 && matches_remain < 101) {
		if (turn == 2) {
			turn = turn_inversion(turn);
			strategy(matches_remain, first, &buffer, input, &check_miscalculation);
			matches_remain = matches_remain - buffer;
			if (matches_remain >= 96) {
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
			input = 0;                         // Так как видимо (предположение) scanw отбрасывает char символы и оставляет то, что было до,
			scanw("%d", &input);			   // то перезапись интовым значением позволит отправить в функцию проверки именно 0,
			stroke_check = check_input(input); // а не предыдущую цифру, сохранившуюся в переменной.
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
		for (col = (getmaxx(stdscr) - strlen(lose)); col != 0; col--) {
			clear();
			if (check_result(turn, matches_remain, input) == 1) {
				mvaddstr(row / 2, col , won);
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
