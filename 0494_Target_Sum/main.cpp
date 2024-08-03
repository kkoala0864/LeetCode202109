#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,1,1,1,1};
	int target = 3;
	Solution* test = new Solution();
	cout << test->findTargetSumWays(input, 3) << endl;
	return 0;
}

