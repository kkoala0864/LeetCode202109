#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 3, 0};
	vector<vector<int>> cost = {{5, 2, 3}, {3, 4, 1}, {1, 2, 1}};
	Solution *test = new Solution();
	cout << test->minCost(input, cost, 3, 3, 3) << endl;
	return 0;
}
