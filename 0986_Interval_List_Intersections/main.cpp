#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> first = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
	vector<vector<int>> second = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
	Solution *test = new Solution();
	vector<vector<int>> result = test->intervalIntersection(first, second);
	for (const auto &iter : result) {
		cout << "[" << iter[0] << ":" << iter[1] << "]" << endl;
	}
	return 0;
}
