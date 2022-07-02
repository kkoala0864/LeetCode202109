#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{17,2,17},{16,16,5},{14,3,19}};
	Solution* test = new Solution();
	cout << test->minCost(input) << endl;
	cout << test->minCost(input) << endl;
	return 0;
}

