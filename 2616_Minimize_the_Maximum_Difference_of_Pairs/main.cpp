#include <Solution.h>

int main(void) {
	vector<int> nums = {10,1,2,7,1,3};
	int p = 2;
	Solution *test = new Solution();
	cout << test->minimizeMax(nums, p) << endl;
	return 0;
}
