#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <deque>

using std::pair;
using std::sort;
using std::deque;

vector<bool> Solution::checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
	vector<pair<int, int>> v;

	for (int i = 0 ; i < nums.size() ; ++i) {
		v.emplace_back(pair<int, int>(nums[i], i));
	}
	sort(v.begin(), v.end());

	vector<bool> result;
	for (int i = 0 ; i < l.size() ; ++i) {
		if ((r[i] - l[i]) <= 1) {
			result.emplace_back(true);
			continue;
		}

		deque<int> d;
		for (int j = 0 ; j < v.size() ; ++j) {
			if (v[j].second < l[i] || v[j].second > r[i]) continue;
			while (d.size() > 2) d.pop_front();

			d.push_back(v[j].first);

			if (d.size() < 3) continue;
			if ((d[1] - d[0]) != (d[2] - d[1])) {
				result.emplace_back(false);
				break;
			}
		}
		if (result.size() < (i+1)) {
			result.emplace_back(true);
		}
	}
	return result;
}
