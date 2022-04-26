#include <Solution.h>

#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,0},{2,2},{3,10},{5,2},{7,0}};
	Solution* test = new Solution();
	cout << test->minCostConnectPoints(input) << endl;
	return 0;
}

