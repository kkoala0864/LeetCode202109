#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 6;
	vector<vector<int>> highways = {{0, 1, 2}, {1, 3, 4}, {0, 2, 6}, {2, 3, 8}, {3, 4, 100}, {4, 5, 200}};
	int discounts = 2;
	Solution *test = new Solution();
	cout << test->minimumCost(n, highways, discounts) << endl;
	return 0;
}
