#include <Solution.h>

vector<int> Solution::smallestSubarrays(vector<int>& nums) {
	int size = nums.size();

	vector<int> result(size, INT_MAX);

	int mx = 0;
	vector<int> cur(32, size-1);
	for (int i = size - 1 ; i >= 0 ; --i) {
		int far = -1;
		mx |= nums[i];
		for (int j = 0 ; j < 32 ; ++j) {
			if ((1 << j) & nums[i]) {
				cur[j] = i;
			}
		}
		for (int j = 0 ; j < 32 ; ++j) {
			if ((1 << j) & mx) {
				far = max(far, cur[j]);
			}
		}
		result[i] = far == -1 ? 1 : far - i + 1;
	}
	return result;
}
