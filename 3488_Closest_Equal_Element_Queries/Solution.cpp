#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>

using std::unordered_map;
using std::set;
using std::min;

int getMinDis(int lhs, int rhs, int size) {
	int result = size;

	int rl = rhs - lhs;
	if (rl < 0) rl = (rl + size) % size;
	int lr = lhs - rhs;
	if (lr < 0) lr = (lr + size) % size;
	result = min(rl, lr);
	return result;
}

vector<int> Solution::solveQueries(vector<int>& nums, vector<int>& queries) {
	vector<int> result;
	int size = nums.size();
	unordered_map<int, set<int>> vToIdx;

	for (int i = 0 ; i < nums.size() ; ++i) {
		vToIdx[nums[i]].emplace(i);
	}

	for (const auto& q : queries) {
		if (vToIdx[nums[q]].size() == 1) {
			result.emplace_back(-1);
			continue;
		}

		int minDistance = size;

		auto iter = vToIdx[nums[q]].lower_bound(q);
		int l = -1, n = -1;
		if (iter != vToIdx[nums[q]].begin()) {
			l = *(std::prev(iter));
		} else {
			l = *(vToIdx[nums[q]].rbegin());
		}
		int ld = getMinDis(q, l, size);
		if(q != *(vToIdx[nums[q]].rbegin())) {
			n = *(std::next(iter));
		} else {
			n = *(vToIdx[nums[q]].begin());
		}
		int nd = getMinDis(q, n, size);
		if (nd < minDistance) {
			minDistance = nd;
		}
		result.emplace_back(min(ld, nd));
	}
	return result;
}
