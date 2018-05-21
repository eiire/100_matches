#include <ctest.h>
#include <matches.h>

CTEST(numOfRemain, check_turn)
{
	// GIVEN
	int check = turn_inversion(1);

	// THEN
	int expected = 2;

	ASSERT_EQUAL(expected, check);

	// GIVEN
	int check2 = turn_inversion(2);

	// THEN
	int expected2 = 1;

	ASSERT_EQUAL(expected2, check2);

}

CTEST(numOfRemain, check_result)
{
	// Проверка на выигрыш в двух случаях
	int expected_win = 1;
	int check_win = check_result(1, -1, 0, 1);
	ASSERT_EQUAL(expected_win, check_win);

	// Проверка на проигрыш в двух случаях
	int expected_lose = 0;
	int check_lose = check_result(2, -1, 0, 1);
	ASSERT_EQUAL(expected_lose, check_lose);

	int expected = 3;
	int check = check_result(0, 0, 0, 0);
	ASSERT_EQUAL(expected, check);
}