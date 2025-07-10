#include <Solution.h>

int main(void) {
	// ["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
	// [[],[0,10],[0,20],[1,30],[0]];
	MyLinkedList* test = new MyLinkedList();
	test->addAtIndex(0, 10);
	test->addAtIndex(0, 20);
	test->addAtIndex(1, 30);
	cout << test->get(0) << endl;
	return 0;
}
