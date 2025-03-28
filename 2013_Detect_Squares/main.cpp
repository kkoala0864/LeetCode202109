#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	DetectSquares *test = new DetectSquares();
	test->add({5, 10});
	test->add({10, 5});
	test->add({10, 10});
	cout << test->count({5, 5}) << endl;
	test->add({3, 0});
	test->add({8, 0});
	test->add({8, 5});
	cout << test->count({3, 5}) << endl;
	test->add({9, 0});
	test->add({9, 8});
	test->add({1, 8});
	cout << test->count({1, 0}) << endl;
	test->add({0, 0});
	test->add({8, 0});
	test->add({8, 8});
	cout << test->count({0, 8}) << endl;

	return 0;
}
