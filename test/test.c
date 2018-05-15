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
