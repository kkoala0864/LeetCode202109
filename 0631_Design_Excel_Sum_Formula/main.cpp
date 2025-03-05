#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Excel* test = new Excel(5, 'E');
	cout << test->get(1, 'A') << endl;
	test->set(1, 'A', 1);
	cout << test->get(1, 'A') << endl;
	cout << test->sum(2, 'B', {"A1", "A1"}) << endl;
	test->set(1, 'A', 2);
	cout << test->get(2, 'B') << endl;
	cout << test->sum(3, 'C', {"B2", "A1:B2"}) << endl;
	test->set(2, 'B', 0);
	cout << test->get(3, 'C') << endl;
	return 0;
}

