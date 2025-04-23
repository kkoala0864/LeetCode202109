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
	FTree ft(maxV);

	int result = 0;
	for (int i = 0 ; i < instructions.size() ; ++i) {
		ft.update(instructions[i], 1);
		int minCnt = ft.query(instructions[i]-1);
		int maxCnt = i + 1 - ft.query(instructions[i]);
		result += min(minCnt, maxCnt);
		result %= mod;
	}
	return result;
}
