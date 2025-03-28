#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> wells = {1, 2, 2};
	vector<vector<int>> pipes = {{1, 2, 1}, {2, 3, 1}};
	Solution *test = new Solution();
	cout << test->minCostToSupplyWater(3, wells, pipes) << endl;
	return 0;
}
