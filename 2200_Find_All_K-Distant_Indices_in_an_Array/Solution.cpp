#include <Solution.h>

vector<int> Solution::findKDistantIndices(vector<int>& nums, int key, int k) {
	set<int> rIdx;
	int curFar = -1;
	int size = nums.size();
	for (int i = 0 ; i < size ; ++i) {
		if (nums[i] == key) {
			curFar = min(size - 1, i + k);
		}
		if (i <= curFar) {
			rIdx.emplace(i);
		}
	}
	curFar = size;
	for (int i = size - 1 ; i >= 0 ; --i) {
		if (nums[i] == key) {
			curFar = max(0, i - k);
		}
		if (i >= curFar) {
			rIdx.emplace(i);
		}
	}
	vector<int> result;
	for (const auto& r : rIdx) result.emplace_back(r);
	return result;
}
