#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};
	Solution* test = new Solution();
	cout << test->maximalNetworkRank(8, input) << endl;
	return 0;
}

