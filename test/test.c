#include <ctest.h>
#include <matches.h>

CTEST(check_queue, turn_inversion)
{
	// GIVEN
	int check = turn_inversion(1);
	int check2 = turn_inversion(2);

	// WHEN
	int expected = 2;
	int expected2 = 1;
	
	// THEN
	ASSERT_EQUAL(expected, check);
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

CTEST(strategy_move, correct_moves_of_man)
{
	int check_miscalculation = 0;   // Хранение значения, которое проверяет, допустил ли человек ошибку
	int buffer = 8; // Примерный ход компьютера(в данном тесте не важно на, что изменится, важно, чтобы сумма 2-х ходов = 11)
	// GIVEN
	int expected = 0;
	// WHEN
	strategy_move(89, 2, &buffer, 3, &check_miscalculation, 78); // если ход компа был 8, то в этом тесте соответственно ход чел. = 3
	int new_miscalculation = check_miscalculation; // (суть теста) Проверим, не изменилась ли проверочная переменная
	// THEN
	ASSERT_EQUAL(expected, new_miscalculation);
}

CTEST(strategy_move, incorrect_moves_of_man) 
{
	// Для случая < 11
	int check_miscalculation = 0;
	int buffer = 7;

	// GIVEN
	int expected_mis = 1; // Так как была совершина ошибка
	int expected_buf = 2; // Ход компьютера, который зависит от 2-х предыдущих
	// WHEN
	strategy_move(79, 2, &buffer, 2, &check_miscalculation, 67);
	int new_miscalculation = check_miscalculation;
	int new_buffer = buffer;
	// THEN
	ASSERT_EQUAL(expected_mis, new_miscalculation);
	ASSERT_EQUAL(expected_buf, new_buffer);


	// Для случая > 11
	check_miscalculation = 0;
	buffer = 7;

	// GIVEN
	expected_mis = 1; // Так как была совершина ошибка
	expected_buf = 8; // Ход компьютера, который зависит от 2-х предыдущих
	// WHEN
	strategy_move(79, 2, &buffer, 7, &check_miscalculation, 67);
	new_miscalculation = check_miscalculation;
	new_buffer = buffer;
	// THEN
	ASSERT_EQUAL(expected_mis, new_miscalculation);
	ASSERT_EQUAL(expected_buf, new_buffer);
}

CTEST(strategy_move, desperate_strategy)
{
	// Для человека
	int check_miscalculation = 0; // Просто потому что функция требует (в мейне изначально тоже равен 0)

	int matches_remain = 85; // Ост. кол-во спичек, при этом мы уже перешли ко 2-му диапазаону
	int buffer = 5; // Ход компьютера в предыдущий раз (ни на что не влияет в данном случае)
	int input = 4; // Ход человека, сделанный после 89 ост. спичек

	// GIVEN
	int expected = 7; // Ход компьютера, который зависит от 2-х предыдущих
	// WHEN
	strategy_move(matches_remain, 1, &buffer, input, &check_miscalculation, 78);
	int new_buffer = buffer;
	// THEN
	ASSERT_EQUAL(expected, new_buffer);


	// Для компьютера
	check_miscalculation = 0; // Просто потому что функция требует (в мейне изначально тоже равен 0)

	int checked_buffer;
	matches_remain = 78; // Ост. кол-во спичек, при этом мы уже перешли ко 3-му диапазаону
	buffer = 5; // Ход компьютера
	input = 6; // Ход человека (корректный)

	// GIVEN
	expected = 1; 
	// WHEN
	strategy_move(matches_remain, 2, &buffer, input, &check_miscalculation, 67); // Порядок хода = 2(второе значение)
	if (buffer >= 0 && buffer <= 10) { // Проверяем значение, которое получилось в следствии рандома
		checked_buffer = 1;				// Так как в этом случае сумма ходов не обязательно должна была
	} else {							// равняться 11
		checked_buffer = 0;
	}
	// THEN
	ASSERT_EQUAL(expected, checked_buffer);
}

CTEST(check_ramain, check_input)
{
	//GIVEN
	int turn = check_input(0);
	int turn1 = check_input(1);
	int turn2 = check_input(2);
	int turn3 = check_input(9);
	int turn4 = check_input(10);
	int turn5 = check_input(11);
	int turn6 = check_input(-1);

	//WHEN
	int expected = 1;
	int expected1 = 0;

	//THEN
	ASSERT_EQUAL(expected1, turn);
	ASSERT_EQUAL(expected, turn1);
	ASSERT_EQUAL(expected, turn2);
	ASSERT_EQUAL(expected, turn3);
	ASSERT_EQUAL(expected, turn4);
	ASSERT_EQUAL(expected1, turn5);
	ASSERT_EQUAL(expected1, turn6);
}

CTEST(strategy, last_situation)
{
	//GIVEN
	int check_miscalculation = 1;
	int first = 2;
	int matches_remain = 9;
	int buffer = 8;
	int input = 3;

	//WHEN
	int new_buffer = 8;
	strategy(matches_remain, first, &buffer, input, &check_miscalculation);

	//THEN
	ASSERT_EQUAL(buffer, new_buffer);

	//GIVEN
	check_miscalculation = 0;
	first = 2;
	matches_remain = 11;
	buffer = 5;
	input = 1;

	//WHEN
	new_buffer = 10;
	strategy(matches_remain, first, &buffer, input, &check_miscalculation);

	//THEN
	ASSERT_EQUAL(buffer, new_buffer);

	//GIVEN
	check_miscalculation = 0;
	first = 1;
	matches_remain = 12;
	buffer = 5;
	input = 6;

	//WHEN
	new_buffer = 5;
	strategy(matches_remain, first, &buffer, input, &check_miscalculation);

	//THEN
	ASSERT_EQUAL(buffer, new_buffer);
}