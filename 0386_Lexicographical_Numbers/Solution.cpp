#include <Solution.h>
#include <iostream>

void dfs(vector<int> &result, int i, int n) {
	if (i > n)
		return;
	result.emplace_back(i);
	for (int j = 0; j < 10; ++j) {
		dfs(result, i * 10 + j, n);
	}
}

vector<int> Solution::lexicalOrder(int n) {
	vector<int> result;
	for (int i = 1; i < 10; ++i) {
		dfs(result, i, n);
	}
	return result;
}
