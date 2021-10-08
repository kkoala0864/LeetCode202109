#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4,3,2,3,5,2,1};
	Solution* test = new Solution();
	cout << test->canPartitionKSubsets(input, 4) << endl;
	return 0;
}

