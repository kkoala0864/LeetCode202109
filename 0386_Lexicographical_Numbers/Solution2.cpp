#include <Solution.h>
#include <iostream>

void dfs(int n, vector<int>& result) {
	int next = result.empty() ? 0 : result.back() * 10;
	for (int i = 0 ; i < 10 ; ++i) {
		int val = next + i;
		if (val > n) break;
		if (val == 0) continue;
		result.emplace_back(val);
		dfs(n, result);
	}
}

vector<int> Solution::lexicalOrder2(int n) {
	vector<int> result;
	dfs(n, result);
	return result;
}
