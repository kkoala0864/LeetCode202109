#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10,15,20};
	Solution* test = new Solution();
	cout << test->minCostClimbingStairs(input) << endl;
	return 0;
}

