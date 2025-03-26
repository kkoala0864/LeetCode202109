#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {4,2,1,4,3,4,5,8,15};
	int k = 3;
	Solution* test = new Solution();
	cout << test->lengthOfLIS(nums, k) << endl;
	return 0;
}

