#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::pair;

long long Solution::findScore(vector<int>& nums) {
	vector<pair<int, int>> l;

	for (int i = 0 ; i < nums.size() ; ++i) {
		l.emplace_back(pair<int, int>(nums[i], i));
	}

	sort(l.begin(), l.end());

	long long result = 0;
	vector<bool> mark(nums.size(), false);
	for (int i = 0 ; i < l.size() ; ++i) {
		int idx = l[i].second;
		if (mark[idx]) continue;
		int val = l[i].first;
		result += (long long)val;
		mark[idx] = true;
		if (idx > 0) {
			mark[idx - 1] = true;
		}
		if (idx <= nums.size() - 1) {
			mark[idx + 1] = true;
		}
	}
	return result;
}
