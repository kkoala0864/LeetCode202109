#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	CountIntervals *test = new CountIntervals();
	test->add(2, 3);
	cout << test->count() << endl;
	return 0;
}
