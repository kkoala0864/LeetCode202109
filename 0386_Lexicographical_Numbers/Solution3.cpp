#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

void dfs(int cur, int n, vector<int> &result) {
	for (int i = 0; i < 10; ++i) {
		if (cur + i > n)
			break;
		result.emplace_back(cur + i);
		dfs((cur + i) * 10, n, result);
	}
}

vector<int> Solution::lexicalOrder3(int n) {
	vector<int> result;
	for (int i = 1; i <= min(n, 9); ++i) {
		result.emplace_back(i);
		dfs(i * 10, n, result);
	}
	return result;
}
