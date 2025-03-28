#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
	Solution *test = new Solution();
	auto result = test->diagonalSort(input);
	for (const auto &r : result) {
		for (const auto &c : r) {
			cout << c << " ";
		}
		cout << endl;
	}
	return 0;
}
