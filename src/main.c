#include "matches.h"
#include "name.h"

int main()
{
	int row, col, stroka = 0, flag = 0, number = 0, travel;
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
	
		mvwprintw(stdscr, row - 2, 0, "Use the keys: key_up, key_down, enter to select...");
		mvwprintw(stdscr, 8, (col - strlen(mode)) / 2, mode);
	
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
			travel = number;
		break;
		}
	}

	clear();
	mvwprintw(stdscr, stroka += 3, (col - strlen(hello)) / 2, "%s", hello);
	mvwprintw(stdscr, stroka += 3, (col - strlen(robot)) / 2, "%s", robot);
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
			fl = 1;
			turn = turn_inversion(turn);
			if (matches_remain == 100) {
				mvwprintw(stdscr, stroka = 0, (col - strlen(nunb)) / 2, "%s", nunb);
			}

			input = 0;
			scanw("%d", &input);
			stroke_check = check_input(input);

			if (stroke_check == 1) {
				matches_remain = matches_remain - input;
				mvwprintw(stdscr, ++stroka, (col - strlen(left)) / 2, "%s", left);
				mvwprintw(stdscr, stroka, (col - strlen(left)) / 2 + strlen(left), "%d", matches_remain);
			} else {
				turn = turn_inversion(turn);
				clear();
				mvwprintw(stdscr, stroka = 0, (col - strlen(left)) / 2, "%s", left);
				mvwprintw(stdscr, stroka, (col - strlen(left)) / 2 + strlen(left), "%d", matches_remain);
				attron(COLOR_PAIR(2));
				mvwprintw(stdscr, ++stroka, (col - strlen(left)) / 2 - 26, "%s", entered);
				attron(COLOR_PAIR(3));
			}
		} else {
			fl = 0;
			if (matches_remain == 100) {
				mvwprintw(stdscr, stroka = 0, (col - strlen(nunb)) / 2, "%s", nunb);
				scanw("%d", &input);
				stroke_check = check_input(input);
			} else {
				input = 0;
				printw(", enter the number: ");
				scanw("%d", &input);
				stroke_check = check_input(input);
			}

			if (stroke_check == 1) {
				matches_remain = matches_remain - input;
				mvwprintw(stdscr, ++stroka, (col - strlen(left)) / 2, "%s", left);
				mvwprintw(stdscr, stroka, (col - strlen(left)) / 2 + strlen(left), "%d", matches_remain);
			} else {
				clear();
				mvwprintw(stdscr, stroka = 0, (col - strlen(left)) / 2, "%s", left);
				mvwprintw(stdscr, stroka, (col - strlen(left)) / 2 + strlen(left), "%d", matches_remain);
				attron(COLOR_PAIR(2));
				mvwprintw(stdscr, ++stroka, (col - strlen(left)) / 2 - 26, "%s", entered);
				attron(COLOR_PAIR(3));
			}
		}
	}

	while (true) {
		for (col = (getmaxx(stdscr) - strlen(lose)); col != 0; col--) {
			clear();
			if (check_result(turn, matches_remain, input, fl) == 1) {
					attron(COLOR_PAIR(1));	
					mvaddstr(row / 2, col, won);
			} else if (check_result(turn, matches_remain, input, fl) == 3){
				printw("Game move!");
			} else {
				attron(COLOR_PAIR(4));	
				mvaddstr(row / 2, col, lose);
			}
			
			refresh();
	    		msleep(130);	
		}
	}

   	endwin();

	return 0;
}
