#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::longestOnes(vector<int>& nums, int k) {
	vector<int> tmp;
	for (const auto& v : nums) {
		if (tmp.empty() || v == 0 || tmp.back() == 0) tmp.emplace_back(v);
		else ++tmp.back();
	}
	nums = move(tmp);

	vector<int> last(k+1, 0), cur(k+1, 0);

	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		int b = min(i + 1, k);
		if (nums[i] > 0) {
			for (int j = 0 ; j <= b ; ++j) {
				cur[j] = last[j] + nums[i];
				result = max(result, cur[j]);
			}
		} else {
			for (int j = 1 ; j <= b ; ++j) {
				cur[j] = last[j-1] + 1;
				result = max(result, cur[j]);
			}
			cur[0] = 0;
		}
		swap(last, cur);
	}
	return result;
}
