

#include "name.h"
#include "matches.h"

int main()
{
	int row_max, col_max, row = 0, flag = 0, number = 0;
	unsigned int i = 0;
	initscr();
	curs_set(0);
	keypad (stdscr, true);
	echo();
	getmaxyx(stdscr, row_max, col_max);

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
			mvwprintw(stdscr, row_max / 2 - 1 + i, (col_max - strlen(mode_man)) / 2 - 2, ">");
			attron(COLOR_PAIR(3));
		}
		else { 
			mvwprintw(stdscr, row_max / 2 + i, (col_max - strlen(mode_man)) / 2 - 2, " ");
		}
		mvwprintw(stdscr, row_max / 2 - 1, (col_max - strlen(mode_man)) / 2, mode_pc);
		mvwprintw(stdscr, row_max / 2, (col_max - strlen(mode_man)) / 2, mode_man);
		
	}

		mvwprintw(stdscr, row_max / 2 - 8, (col_max - strlen(hello_message)) / 2, "%s", hello_message);
		mvwprintw(stdscr, row_max - 2, 0, "%s", keys_message);
		mvwprintw(stdscr, row_max / 2 - 4, (col_max - strlen(mode_message)) / 2, mode_message);
	
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
	mvwprintw(stdscr, row_max / 2 - 4, (col_max - strlen(robot_message)) / 2, "%s", robot_message);
	mvwprintw(stdscr, row_max / 2, (col_max - strlen(choice_message)) / 2 , "%s", choice_message);

	int turn;
	if (number == 0) {
		turn = check_turn(row, col_max);
	} else {
		turn = 1;
	}

	clear();
	int first = turn;
	int input = 0, stroke_check, matches_remain = 100, buffer = 0, check_miscalculation = 0, fl_result;

	while (matches_remain > 0 && matches_remain < 101) {
		if (turn == 2 && number == 0) {
			fl_result = 1;
			turn = turn_inversion(turn);
			strategy(matches_remain, first, &buffer, input, &check_miscalculation);
			matches_remain = matches_remain - buffer;

			if (matches_remain > 89) {
				row = -1;
			}
			mvwprintw(stdscr, ++row, (col_max - strlen(remainder_message)) / 2 - 26, "%s", took_message);
			mvwprintw(stdscr, row, (col_max - strlen(remainder_message)) / 2 - 18, "%d", buffer);
			mvwprintw(stdscr, row, (col_max - strlen(remainder_message)) / 2 , "%s", remainder_message);
			mvwprintw(stdscr, row, (col_max + strlen(remainder_message)) / 2, "%d", matches_remain);
			mvwprintw(stdscr, row, (col_max - strlen(ymove_message)) / 2 + 30, "%s", ymove_message);
		} else if (turn == 1 && number == 0) {
			if (row == getmaxy(stdscr)) {
				clear();
				row = 0;
				mvwprintw(stdscr, ++row, col_max / 2 - strlen(remainder_message) - 13, "%s", remainder_message);
				mvwprintw(stdscr, row, col_max / 2 - 13, "%d", matches_remain);
			}
			fl_result = 1;
			turn = turn_inversion(turn);
			if (matches_remain == 100) {
				clear();
				mvwprintw(stdscr, row = 0, (col_max - strlen(numb_message)) / 2, "%s", numb_message);
			}

			input = 0;
			scanw("%d", &input);
			stroke_check = check_input(input);

			if (stroke_check == 1) {
				if (row == getmaxy(stdscr)) {
					clear();
					row = 0;
					mvwprintw(stdscr, ++row, col_max / 2 - strlen(remainder_message) - 13, "%s", remainder_message);
					mvwprintw(stdscr, row, col_max / 2 - 13, "%d", matches_remain);
				}
				matches_remain = matches_remain - input;
				mvwprintw(stdscr, ++row, (col_max - strlen(remainder_message)) / 2, "%s", remainder_message);
				mvwprintw(stdscr, row, (col_max + strlen(remainder_message)) / 2, "%d", matches_remain);
			} else {
				if (row == getmaxy(stdscr)) {
					clear();
					row = 0;
					mvwprintw(stdscr, ++row, col_max / 2 - strlen(remainder_message) - 13, "%s", remainder_message);
					mvwprintw(stdscr, row, col_max / 2 - 13, "%d", matches_remain);
				}
				turn = turn_inversion(turn);
				clear();
				mvwprintw(stdscr, row = 0, (col_max - strlen(remainder_message)) / 2, "%s", remainder_message);
				mvwprintw(stdscr, row, (col_max + strlen(remainder_message)) / 2, "%d", matches_remain);
				attron(COLOR_PAIR(2));
				mvwprintw(stdscr, ++row, (col_max - strlen(errored_message)) / 2, "%s", errored_message);
				attron(COLOR_PAIR(3));
			}
		} else {
			fl_result = 0;
			if (matches_remain == 100) {
				row = -1;
				mvwprintw(stdscr, ++row, (col_max - strlen(enter_message)) / 2, "%s", enter_message);
				scanw("%d", &input);
				stroke_check = check_input(input);
			} else {
				if (row == getmaxy(stdscr)) {
					clear();
					row = 0;
					mvwprintw(stdscr, ++row, col_max / 2 - strlen(remainder_message) - 13, "%s", remainder_message);
					mvwprintw(stdscr, row, col_max / 2 - 13, "%d", matches_remain);
				}
				input = 0;
				mvwprintw(stdscr, row, col_max / 2 + 9, "%s", numb_message);
				scanw("%d", &input);
				stroke_check = check_input(input);
			}

			if (stroke_check == 1) {
				if (row == getmaxy(stdscr)) {
					clear();
					row = 0;
					mvwprintw(stdscr, ++row, col_max / 2 - strlen(remainder_message) - 13, "%s", remainder_message);
					mvwprintw(stdscr, row, col_max / 2 - 13, "%d", matches_remain);
				}
				matches_remain = matches_remain - input;
				mvwprintw(stdscr, ++row, col_max / 2 - strlen(remainder_message) - 13, "%s", remainder_message);
				mvwprintw(stdscr, row, col_max / 2 - 13, "%d", matches_remain);
			} else {
				clear();
				mvwprintw(stdscr, row = 0, (col_max - strlen(remainder_message)) / 2 - 2, "%s", remainder_message);
				mvwprintw(stdscr, row, (col_max + strlen(remainder_message)) / 2 - 2, "%d", matches_remain);
				attron(COLOR_PAIR(2));
				mvwprintw(stdscr, 0, 0, "%s", error_message);
				++row;
				attron(COLOR_PAIR(3));
			}
		}
	}

	loked_result(turn, matches_remain, input, fl_result, col_max, row_max, won, lose, over);

   	endwin();

	return 0;
}