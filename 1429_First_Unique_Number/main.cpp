#include <Solution.h>

int main(void) {
	vector<int> input = {2, 3, 5};
	FirstUnique *test = new FirstUnique(input);
	cout << test->showFirstUnique() << endl;
	test->add(5);
	cout << test->showFirstUnique() << endl;
	test->add(2);
	cout << test->showFirstUnique() << endl;
	test->add(3);
	cout << test->showFirstUnique() << endl;

	return 0;
}
