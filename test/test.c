#include <ctest.h>
#include <matches.h>

CTEST(numOfRemain, check_turn)
{
	// GIVEN
	int check = turn_inversion(1);

	// THEN
	int expected = 2;

	ASSERT_EQUAL(expected, check);
}