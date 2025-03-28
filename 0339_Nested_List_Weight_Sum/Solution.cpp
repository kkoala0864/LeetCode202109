#include <Solution.h>
#include <iostream>

void dfs(const vector<NestedInteger> &list, int depth, int &result) {
	for (auto &n : list) {
		if (n.isInteger()) {
			result += (depth * n.getInteger());
		} else {
			dfs(n.getList(), depth + 1, result);
		}
	}
}

int Solution::depthSum(vector<NestedInteger> &nestedList) {
	int depth = 1;
	int result = 0;
	dfs(nestedList, depth, result);
	return result;
}
