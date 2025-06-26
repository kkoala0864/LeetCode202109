#include <Solution.h>

int main(void) {
	SegTree tree(10);

	for (int i = 0; i < 10; ++i) {
		tree.update(i, i + 1, 1, 0, 10);
	}

	for (int i = 0; i < 10; ++i) {
		cout << tree.query(0, i, 1, 0, 10) << endl;
	}

	RangeTree Rtree(8);
	Rtree.rangeAdd(0, 7, 1, 1, 0, 8);
	Rtree.rangeAdd(2, 5, 3, 1, 0, 8);
	cout << "range sum : " << Rtree.rangeSum(0, 7, 1, 0, 8) << endl;
	cout << "range sum : " << Rtree.rangeSum(3, 4, 1, 0, 8) << endl;
	return 0;
}
