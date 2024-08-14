#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	StockPrice* test = new StockPrice();
	test->update(1, 10);
	test->update(2, 5);
	cout << test->current() << endl;
	cout << test->maximum() << endl;
	test->update(1, 3);
	cout << test->maximum() << endl;
	test->update(4, 2);
	cout << test->minimum() << endl;
	return 0;
}

