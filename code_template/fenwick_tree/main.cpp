#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	fenwickTree tree(10);

	for (int i = 0; i < 10; ++i) {
		tree.update(i, i + 1);
	}
	for (int i = 0; i < 10; ++i) {
		cout << tree.sum(i) << endl;
	}
	return 0;
}
