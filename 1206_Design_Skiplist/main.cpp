#include <Solution.h>

int main(void) {
	//["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase", "search"]
	//[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
	Skiplist* test = new Skiplist();
	test->add(1);
	test->add(2);
	test->add(3);
	cout << test->search(0) << endl;
	test->add(4);
	cout << test->search(1) << endl;
	cout << test->erase(0) << endl;
	cout << test->erase(1) << endl;
	cout << test->search(1) << endl;
	return 0;
}
