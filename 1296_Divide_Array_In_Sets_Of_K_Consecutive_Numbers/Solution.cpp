#include <Solution.h>
#include <iostream>
#include <map>

using std::map;

bool Solution::isPossibleDivide(vector<int> &nums, int k) {
	if (nums.size() % k != 0)
		return false;

	map<int, int> m;
	for (const auto &v : nums)
		++m[v];

	while (m.size() > 0) {
		int start = m.begin()->first;
		int cnt = m.begin()->second;
		for (int i = 0; i < k; ++i) {
			if (m.count(start + i) && m[start + i] >= cnt) {
				m[start + i] -= cnt;
				if (m[start + i] == 0)
					m.erase(start + i);
			} else {
				return false;
			}
		}
	}
	return true;
}
