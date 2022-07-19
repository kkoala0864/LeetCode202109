#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,5,3},{2,9,4}};
	Solution* test = new Solution();
	cout << test->minCostII(input) << endl;
	return 0;
}

