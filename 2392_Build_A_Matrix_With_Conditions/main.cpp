#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int k = 8;
	vector<vector<int>> rowConditions = {{1, 2}, {7, 3}, {4, 3}, {5, 8}, {7, 8}, {8, 2}, {5, 8}, {3, 2}, {1, 3}, {7, 6}, {4, 3}, {7, 4}, {4, 8}, {7, 3}, {7, 5}};
	vector<vector<int>> colConditions = {{5, 7}, {2, 7}, {4, 3}, {6, 7}, {4, 3}, {2, 3}, {6, 2}};
	Solution *test = new Solution();
	auto result = test->buildMatrix(k, rowConditions, colConditions);
	for (const auto &r : result) {
		for (const auto &c : r) {
			cout << c << " ";
		}
		cout << endl;
	}
	return 0;
}
