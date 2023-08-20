#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {1,3,2,3,1,3};
	Solution* test = new Solution();
	cout << test->longestEqualSubarray(nums, 3) << endl;
	return 0;
}

