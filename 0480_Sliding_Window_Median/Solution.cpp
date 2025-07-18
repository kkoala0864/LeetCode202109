#include <Solution.h>

void sub(map<int, int>& m, int v) {
	--m[v];
	if (m[v] == 0) m.erase(v);
}

vector<double> Solution::medianSlidingWindow(vector<int>& nums, int k) {
	map<int, int> maxH, minH;
	int minCnt = 0, maxCnt = 0;

	vector<double> result;
	for (int i = 0 ; i < nums.size() ; ++i) {
		++maxH[nums[i]];
		int v = maxH.rbegin()->first;
		sub(maxH, v);
		++minH[v];
		++minCnt;

		if (i >= k) {
			if (minH.count(nums[i-k])) {
				sub(minH, nums[i-k]);
				--minCnt;
			} else if (maxH.count(nums[i-k])) {
				sub(maxH, nums[i-k]);
				--maxCnt;
			}
		}

		if (i >= k-1) {
			while (abs(minCnt - maxCnt) > 1) {
				if (minCnt > maxCnt) {
					int v = minH.begin()->first;
					++maxH[v];
					sub(minH, v);
					--minCnt;
					++maxCnt;
				} else {
					int v = maxH.rbegin()->first;
					++minH[v];
					sub(maxH, v);
					--maxCnt;
					++minCnt;
				}
			}
			if (minCnt == maxCnt) {
				long long v = (long long)minH.begin()->first + (long long)maxH.rbegin()->first;
				result.emplace_back(v * 1.0 /2);
			} else {
				result.emplace_back(minCnt > maxCnt ? minH.begin()->first : maxH.rbegin()->first);
			}
		}
	}
	return result;
}
