#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	AllOne* test = new AllOne();
	test->inc("hello");
	test->inc("hello");
	cout << test->getMaxKey() << endl;
	cout << test->getMinKey() << endl;
	test->inc("leet");
	cout << test->getMaxKey() << endl;
	cout << test->getMinKey() << endl;
	return 0;
}

