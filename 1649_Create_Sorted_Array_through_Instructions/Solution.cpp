#include <Solution.h>
#include <iostream>
#include <algorithm>

int Solution::createSortedArray(vector<int>& instructions) {
	int mod = 1e9 + 7;

	int maxV = 0;
	for (const auto& v : instructions) {
		maxV = max(maxV, v);
	}
	++maxV;
	BTree t(maxV);

	int result = 0;

	for (const auto& v : instructions) {
		t.update(v, 1, 1, 0, maxV);
		int minCnt = t.query(0, v-1, 1, 0, maxV);
		int maxCnt = t.query(v + 1, maxV, 1, 0, maxV);
		result += min(minCnt, maxCnt);
		result %= mod;
	}
	return result;
}
