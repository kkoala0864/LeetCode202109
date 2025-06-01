#include <Solution.h>

int main(void) {
	vector<int> nums = {99,16,69,46,18,81,66,62,30,31,15,72};
	long long target = 5488845120;
	Solution *test = new Solution();
	cout << test->checkEqualPartitions(nums, target) << endl;
	return 0;
}
