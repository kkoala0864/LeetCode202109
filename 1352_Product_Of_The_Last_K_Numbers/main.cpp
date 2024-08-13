#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ProductOfNumbers* test = new ProductOfNumbers();
	test->add(3);
	test->add(0);
	test->add(2);
	test->add(5);
	test->add(4);
	cout << test->getProduct(2) << endl;
	cout << test->getProduct(3) << endl;
	cout << test->getProduct(4) << endl;
	test->add(8);
	cout << test->getProduct(2) << endl;
	return 0;
}

