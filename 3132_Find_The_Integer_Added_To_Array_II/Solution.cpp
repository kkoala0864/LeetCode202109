#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
using std::greater;
using std::map;
using std::sort;

int Solution::minimumAddedInteger(vector<int> &nums1, vector<int> &nums2) {
	int size = nums2.size();

	sort(nums2.begin(), nums2.end(), greater<int>());
	map<int, int, greater<int>> m;
	for (const auto &v : nums1)
		++m[v];

	vector<int> diff;
	for (int i = 0; i < size - 1; ++i) {
		diff.emplace_back(nums2[i] - nums2[i + 1]);
	}

	for (const auto &v : m) {
		auto tmp = m;
		int cur = v.first;
		--tmp[cur];
		if (tmp[cur] == 0)
			tmp.erase(cur);

		bool find = true;
		for (int i = 0; i < diff.size(); ++i) {
			cur -= diff[i];
			if (tmp.count(cur) == 0) {
				find = false;
				break;
			}
			--tmp[cur];
			if (tmp[cur] == 0)
				tmp.erase(cur);
		}
		if (find) {
			return nums2[0] - v.first;
		}
	}
	return 0;
}
