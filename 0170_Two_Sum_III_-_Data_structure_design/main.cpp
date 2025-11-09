#include <Solution.h>

int main(void) {
	TwoSum *test = new TwoSum();
	test->add(1);
	test->add(3);
	test->add(5);
	cout << test->find(4) << endl;
	cout << test->find(7) << endl;
	return 0;
}
