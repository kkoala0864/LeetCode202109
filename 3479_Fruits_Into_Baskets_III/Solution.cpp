#include <Solution.h>
#include <iostream>
#include <climits>

using std::cout;
using std::endl;

int Solution::numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
	STree tree(baskets);
	int result = 0;
	int size = fruits.size();
	for (int i = 0; i < size; ++i) {
		int idx = tree.query(fruits[i]);
		cout << idx << endl;
		if (idx == -1) {
			++result;
		} else {
			tree.set(INT_MIN, idx, 1, 0, size - 1);
		}
	}
	return result;
}
