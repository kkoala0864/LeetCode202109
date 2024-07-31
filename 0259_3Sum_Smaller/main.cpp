#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {0};
	int target = 0;
	Solution* test = new Solution();
	cout << test->threeSumSmaller(nums, target) << endl;
	return 0;
}

