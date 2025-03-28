#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
using std::pair;

vector<int> Solution::smallestRange(vector<vector<int>> &nums) {
	vector<pair<int, int>> list;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < nums[i].size(); ++j) {
			list.emplace_back(pair<int, int>(nums[i][j], i));
		}
	}

	sort(list.begin(), list.end());

	int l = 0;
	int minSize = INT_MAX;
	vector<int> result = {INT_MAX, INT_MAX};
	vector<int> cnt(nums.size(), 1);
	int size = nums.size();

	for (int i = 0; i < list.size(); ++i) {
		--cnt[list[i].second];
		if (cnt[list[i].second] == 0)
			--size;
		while (l <= i && size == 0) {
			if (list[i].first - list[l].first + 1 < minSize) {
				minSize = list[i].first - list[l].first + 1;
				result[0] = list[l].first;
				result[1] = list[i].first;
			}
			++cnt[list[l].second];
			if (cnt[list[l].second] > 0)
				++size;
			++l;
		}
	}
	return result;
}
