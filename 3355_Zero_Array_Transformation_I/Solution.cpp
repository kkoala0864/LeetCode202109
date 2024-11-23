#include <Solution.h>
#include <iostream>
#include <map>

using std::map;

bool Solution::isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
	map<int, int> m;

	for (const auto& q : queries) {
		++m[q[0]];
		--m[q[1]+1];
	}

	vector<int> idx;
	vector<int> v;
	idx.emplace_back(-1);
	v.emplace_back(0);
	int cnt = 0;
	for (const auto& e : m) {
		cnt += e.second;
		idx.emplace_back(e.first);
		v.emplace_back(cnt);
	}

	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] == 0) continue;
		int iv = lower_bound(idx.begin(), idx.end(), i) - idx.begin();
		if (iv == idx.size()) return false;
		if (idx[iv] > i) --iv;
		if (v[iv] < nums[i]) return false;
	}
	return true;
}
