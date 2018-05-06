#include "matches.h"

int main()
{
	/*int row, col;
	const char *hello = "Welcome to the game 100 matches!";
	const char *robot = "I am a robot that will be against you";
	const char *choice = "Choose how you want to go: ";
	const char *won = "You won!";
	const char *lose = "You lose!";*/

	initscr();	

	getmaxyx(stdscr, row, col);

	curs_set(0);
	echo();

	mvwprintw(stdscr, 1 , (col - strlen(hello)) / 2, "%s", hello);
	mvwprintw(stdscr, 2 , (col - strlen(robot)) / 2, "%s", robot);
	mvwprintw(stdscr, 3 , 0 , "%s", choice);

	int turn = check_turn();
	int first = turn;

	int input, stroke_check, matches_remain = 100, buffer;

	while (matches_remain >= 0 && matches_remain < 101 
			&& matches_remain != 2 && matches_remain != 0) {
		if (turn == 2) {
			turn = turn_inversion(turn);
			strategy(matches_remain, first, &buffer);
			matches_remain = matches_remain - buffer;
			printw("I took %d left %d. Your move!\n", buffer, matches_remain);
		} else {
			turn = turn_inversion(turn);
			scanw("%d", &input);
			stroke_check = check_input(input);
			if (stroke_check == 1) {
				matches_remain = matches_remain - input;
				printw("Left %d\n", matches_remain);
			} else {
				turn = turn_inversion(turn);
				printw("You entered an invalid value, please try again: ");
			}
		}
	}

	if (turn == 2 && (matches_remain == 2 || matches_remain == 1
			|| matches_remain == 0)) {
		mvwprintw(stdscr, row / 2 , (col - strlen(won)) / 2, "%s", won);
	} else if (turn == 1 && matches_remain < 0) {
		mvwprintw(stdscr, row / 2 , (col - strlen(lose)) / 2, "%s", lose);
	} else {
		mvwprintw(stdscr, row / 2 , (col - strlen(lose)) / 2, "%s", lose);
	}

	getch();    
   	endwin();

	return 0;
}
