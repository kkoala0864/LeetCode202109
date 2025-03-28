#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
	Solution *test = new Solution();
	test->setZeroes3(input);
	for (const auto iter : input) {
		for (const auto iter2 : iter) {
			cout << iter2 << "  ";
		}
		cout << endl;
	}
	return 0;
}
