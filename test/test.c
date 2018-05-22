#include <ctest.h>
#include <matches.h>

CTEST(check_queue, check_turn)
{
	// GIVEN
	int check = turn_inversion(1);
	// WHEN
	int expected = 2;
	// THEN
	ASSERT_EQUAL(expected, check);

	// GIVEN
	int check2 = turn_inversion(2);
	// WHEN
	int expected2 = 1;
	// THEN
	ASSERT_EQUAL(expected2, check2);
}

CTEST(check_result, check_win_lose_end)
{
	// GIVEN
	int expected_win = 1;
	// WHEN
	int check_win = check_result(1, -1, 0, 1);
	// THEN
	ASSERT_EQUAL(expected_win, check_win);

	// GIVEN
	int expected_lose = 0;
	// WHEN
	int check_lose = check_result(2, -1, 0, 1);
	// THEN
	ASSERT_EQUAL(expected_lose, check_lose);

	// GIVEN
	int expected = 3;
	// WHEN
	int check = check_result(0, 0, 0, 0);
	// THEN
	ASSERT_EQUAL(expected, check);
}



