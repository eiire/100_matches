#include <ctest.h>
#include <matches.h>

CTEST(numOfRemain , test_step_hourse)
{
	// GIVEN
	int check = turn_inversion(1);

	// THEN
	int expected = 2;

	ASSERT_EQUAL(expected, check);
}