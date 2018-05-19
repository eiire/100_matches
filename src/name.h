#ifndef NAME_H
#define NAME_H

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #define msleep(msec) Sleep(msec)
#else
    #include <unistd.h>
    #define msleep(msec) usleep(msec * 1000)
#endif

	const char *mode = "Select a game mode";
	const char *man = "Man vs. Man";
	const char *pc = "Man vs. PC";
    const char *hello = "Welcome to the game 100 matches!";
    const char *robot = "I am a robot that will be against you!";
    const char *choice = "Choose how you want to go: ";
    const char *took = "I took: ";
	const char *entered = "Error, please try again: ";
    const char *left = "Remainder: ";
    const char *ymove = "Your move: ";
    const char *won = "You won!";
    const char *lose = "You lose!";
    const char *numb = "Your number: ";
    const char *over = "Game over! last loser =)";
    const char *NUMBER = "Enter the number: ";
    const char *remaind = "Remainder: ";
    
#endif