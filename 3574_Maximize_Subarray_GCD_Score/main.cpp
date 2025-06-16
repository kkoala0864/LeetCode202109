#include <Solution.h>

int main(void) {
	vector<int> nums = {2, 4};
	int k = 1;
	Solution *test = new Solution();
	cout << test->maxGCDScore(nums, k) << endl;
	return 0;
}
