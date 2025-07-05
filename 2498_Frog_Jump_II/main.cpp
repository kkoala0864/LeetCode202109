#include <Solution.h>

int main(void) {
	vector<int> nums = {0,2,5,6,7};
	Solution *test = new Solution();
	cout << test->maxJump(nums) << endl;
	return 0;
}
