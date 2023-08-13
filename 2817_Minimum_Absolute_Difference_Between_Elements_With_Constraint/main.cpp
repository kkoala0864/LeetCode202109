#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {1,2,3,4};
	Solution* test = new Solution();
	cout << test->minAbsoluteDifference(nums, 3) << endl;
	return 0;

}

