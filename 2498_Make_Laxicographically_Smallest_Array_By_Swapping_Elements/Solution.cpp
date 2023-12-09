#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::min;
using std::pair;

vector<int> Solution::lexicographicallySmallestArray(vector<int>& nums, int limit) {
	int size = nums.size();

	vector<pair<int, int>> idxs;
	for (int i = 0 ; i < size ; ++i) {
		idxs.push_back(pair<int, int>(nums[i], i));
	}

	sort(idxs.begin(), idxs.end());
	vector<int> m(size, 0);
	vector<vector<int>> lists;

	int l = 0;
	vector<int> tmp;
	for (int i = 0 ; i < size ; ++i) {
		if (!tmp.empty() && (idxs[i].first - tmp.back()) > limit) {
			sort(tmp.begin(), tmp.end(), std::greater<int>());
			lists.emplace_back(tmp);
			tmp.clear();
		}
		m[idxs[i].second] = lists.size();
		tmp.emplace_back(idxs[i].first);
	}

	sort(tmp.begin(), tmp.end(), std::greater<int>());
	lists.emplace_back(tmp);
	for (int i = 0 ; i < size ; ++i) {
		int li = m[i];
		nums[i] = lists[li].back();
		lists[li].pop_back();
	}
	return nums;
}
