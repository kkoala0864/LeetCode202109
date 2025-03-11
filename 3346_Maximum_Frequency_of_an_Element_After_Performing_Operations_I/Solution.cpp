#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::max;

int Solution::maxFrequency(vector<int>& nums, int k, int numOperations) {
	int maxV = INT_MIN;
	for (const auto& v : nums) maxV = max(maxV, v);
	vector<int> cnts(maxV + k + 1, 0);

	for (const auto& v : nums) {
		++cnts[v];
	}
	vector<int> preSum(maxV + k + 1, 0);
	for (int i = 1 ; i < cnts.size() ; ++i) {
		preSum[i] = preSum[i-1] + cnts[i];
	}

	int result = 0;
	for (int i = 0 ; i < cnts.size() ; ++i) {
		int l = max(0, i - k);
		int r = min(i + k, (int)cnts.size() - 1);

		int same = cnts[i];

		int convertable = preSum[r] - (l > 0 ? preSum[l-1] : 0) - same;

		if (convertable > numOperations) {
			result = max(result, same + numOperations);
		} else {
			result = max(result, same + convertable);
		}
	}
	return result;
}
