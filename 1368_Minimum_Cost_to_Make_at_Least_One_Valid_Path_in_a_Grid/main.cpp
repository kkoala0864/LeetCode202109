#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
	Solution* test = new Solution();
	cout << test->minCost(input) << endl;
	return 0;
}

