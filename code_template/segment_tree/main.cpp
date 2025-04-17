#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	SegTree tree(10);

	for (int i = 0; i < 10; ++i) {
		tree.update(i, i + 1, 1, 0, 10);
	}

	for (int i = 0; i < 10; ++i) {
		cout << tree.query(0, i, 1, 0, 10) << endl;
	}
	return 0;
}
