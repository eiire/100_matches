#include "name.h"
#include "matches.h"

int main()
{
	int row, col, stroka = 0, flag = 0, number = 0;
	unsigned int i = 0;
	initscr();
	curs_set(0);
	keypad (stdscr, true);
	echo();
	getmaxyx(stdscr, row, col);

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_YELLOW);
	attron(COLOR_PAIR(3));

	while (flag == 0) {
	clear();
	
	for (i = 0; i < 2; i++) {
		if (i == number) {
			attron(COLOR_PAIR(2));
			mvwprintw(stdscr, row / 2 - 1 + i, (col - strlen(man)) / 2 - 2, ">");
			attron(COLOR_PAIR(3));
		}
		else { 
			mvwprintw(stdscr, row / 2 + i, (col - strlen(man)) / 2 - 2, " ");
		}
		mvwprintw(stdscr, row / 2 - 1, (col - strlen(man)) / 2, pc);
		mvwprintw(stdscr, row / 2, (col - strlen(man)) / 2, man);
		
	}

		mvwprintw(stdscr, row / 2 - 8, (col - strlen(hello)) / 2, "%s", hello);
		mvwprintw(stdscr, row - 2, 0, "Use the keys: key_up, key_down, enter to select...");
		mvwprintw(stdscr, row / 2 - 4, (col - strlen(mode)) / 2, mode);
	
		switch (getch()) {
		case KEY_UP:
			if (number > 0)
			number--;
		break;
	            
		case KEY_DOWN:
			if (number != 1)
			number++;
		break;
	        
		case 10:
			flag = 1;
		break;
		}
	}

	clear();
	mvwprintw(stdscr, row / 2 - 4, (col - strlen(robot)) / 2, "%s", robot);
	mvwprintw(stdscr, row / 2, (col - strlen(choice)) / 2 , "%s", choice);

	int turn;
	if (number == 0) {
		turn = check_turn(stroka, col);
	} else {
		turn = 1;
	}

	clear();
	int first = turn;
	int input = 0, stroke_check, matches_remain = 100, buffer = 0, check_miscalculation = 0, fl;

	while (matches_remain > 0 && matches_remain < 101) {
		if (turn == 2 && number == 0) {
			fl = 1;
			turn = turn_inversion(turn);
			strategy(matches_remain, first, &buffer, input, &check_miscalculation);
			matches_remain = matches_remain - buffer;

			if (matches_remain > 89) {
				stroka = -1;
			}
			mvwprintw(stdscr, ++stroka, (col - strlen(left)) / 2 - 26, "%s", took);
			mvwprintw(stdscr, stroka, (col - strlen(left)) / 2 - 18, "%d", buffer);
			mvwprintw(stdscr, stroka, (col - strlen(left)) / 2 , "%s", left);
			mvwprintw(stdscr, stroka, (col - strlen(left)) / 2 + strlen(left), "%d", matches_remain);
			mvwprintw(stdscr, stroka, (col - strlen(ymove)) / 2 + 30, "%s", ymove);
		} else if (turn == 1 && number == 0) {
			if (stroka == getmaxy(stdscr)) {
				clear();
				stroka = 0;
				mvwprintw(stdscr, ++stroka, col / 2 - strlen(left) - 13, "%s", left);
				mvwprintw(stdscr, stroka, col / 2 - 13, "%d", matches_remain);
			}
			fl = 1;
			turn = turn_inversion(turn);
			if (matches_remain == 100) {
				clear();
				mvwprintw(stdscr, stroka = 0, (col - strlen(numb)) / 2, "%s", numb);
			}

			input = 0;
			scanw("%d", &input);
			stroke_check = check_input(input);

			if (stroke_check == 1) {
				if (stroka == getmaxy(stdscr)) {
					clear();
					stroka = 0;
					mvwprintw(stdscr, ++stroka, col / 2 - strlen(left) - 13, "%s", left);
					mvwprintw(stdscr, stroka, col / 2 - 13, "%d", matches_remain);
				}
				matches_remain = matches_remain - input;
				mvwprintw(stdscr, ++stroka, (col - strlen(left)) / 2, "%s", left);
				mvwprintw(stdscr, stroka, (col - strlen(left)) / 2 + strlen(left), "%d", matches_remain);
			} else {
				if (stroka == getmaxy(stdscr)) {
					clear();
					stroka = 0;
					mvwprintw(stdscr, ++stroka, col / 2 - strlen(left) - 13, "%s", left);
					mvwprintw(stdscr, stroka, col / 2 - 13, "%d", matches_remain);
				}
				turn = turn_inversion(turn);
				clear();
				mvwprintw(stdscr, stroka = 0, (col - strlen(left)) / 2, "%s", left);
				mvwprintw(stdscr, stroka, (col - strlen(left)) / 2 + strlen(left), "%d", matches_remain);
				attron(COLOR_PAIR(2));
				mvwprintw(stdscr, ++stroka, (col - strlen(entered)) / 2, "%s", entered);
				attron(COLOR_PAIR(3));
			}
		} else {
			fl = 0;
			if (matches_remain == 100) {
				stroka = -1;
				mvwprintw(stdscr, ++stroka, (col - strlen(NUMBER)) / 2, "%s", NUMBER);
				scanw("%d", &input);
				stroke_check = check_input(input);
			} else {
				if (stroka == getmaxy(stdscr)) {
					clear();
					stroka = 0;
					mvwprintw(stdscr, ++stroka, col / 2 - strlen(left) - 13, "%s", left);
					mvwprintw(stdscr, stroka, col / 2 - 13, "%d", matches_remain);
				}
				input = 0;
				mvwprintw(stdscr, stroka, col / 2 + 9, "%s", numb);
				scanw("%d", &input);
				stroke_check = check_input(input);
			}

			if (stroke_check == 1) {
				if (stroka == getmaxy(stdscr)) {
					clear();
					stroka = 0;
					mvwprintw(stdscr, ++stroka, col / 2 - strlen(left) - 13, "%s", left);
					mvwprintw(stdscr, stroka, col / 2 - 13, "%d", matches_remain);
				}
				matches_remain = matches_remain - input;
				mvwprintw(stdscr, ++stroka, col / 2 - strlen(left) - 13, "%s", left);
				mvwprintw(stdscr, stroka, col / 2 - 13, "%d", matches_remain);
			} else {
				clear();
				mvwprintw(stdscr, stroka = 0, (col - strlen(remaind)) / 2 - 2, "%s", remaind);
				mvwprintw(stdscr, stroka, (col - strlen(remaind)) / 2 + strlen(remaind) - 2, "%d", matches_remain);
				attron(COLOR_PAIR(2));
				mvwprintw(stdscr, 0, 0, "%s", error);
				++stroka;
				attron(COLOR_PAIR(3));
			}
		}
	}

	loked_result(turn, matches_remain, input, fl, col, row, won, lose, over);

   	endwin();

	return 0;
}