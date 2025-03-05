#include <Solution.h>
#include <iostream>

void dfs(const NestedInteger& v, int curl, vector<int>& lv) {
	if (lv.size() < curl) lv.emplace_back(0);
	if (v.isInteger()) {
		lv[curl - 1] += v.getInteger();
	} else {
		auto list = v.getList();
		for (const auto& nv : list) {
			dfs(nv, curl + 1, lv);
		}
	}
}

int Solution::depthSumInverse(vector<NestedInteger>& nestedList) {
	vector<int> lv(1, 0);

	for (const auto& v : nestedList) {
		dfs(v, 1, lv);
	}
	int result = 0;
	for (int i = 0 ; i < lv.size() ; ++i) {
		result += (lv[i] * (lv.size() - i));
	}
	return result;
}
