#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::min;

int Solution::minOperations(vector<vector<int>>& grid, int x) {
	vector<int> list;
	for (const auto& iter : grid) {
		for (const auto& v : iter) list.emplace_back(v);
	}
	sort(list.begin(), list.end());

	int curCnt = 0;
	for (int i = 0 ; i < list.size() ; ++i) {
		int diff = abs(list[i] - list[0]);
		if (diff % x) return -1;
		curCnt += (diff/x);
	}
	int result = curCnt;
	for (int i = 1 ; i < list.size() ; ++i) {
		int offset = (list[i] - list[i-1]) / x;
		curCnt += (i * offset);
		curCnt -= ((list.size() - i) * offset);
		result = min(result, curCnt);
	}
	return result;
}
