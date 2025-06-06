#include <Solution.h>

int main(void) {
	vector<int> nums = {145,145,149,148,146,148,146,148,147,145};
	Solution *test = new Solution();
	cout << test->numberOfSubarrays(nums) << endl;
	return 0;
}
