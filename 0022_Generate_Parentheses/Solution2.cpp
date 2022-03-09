#include <Solution.h>
#include <iostream>

void dfs2(string local, int left, int right, vector<string>& result) {
	if (left == 0 && right == 0) {
		result.emplace_back(local);
		return;
	}
	if (left > 0) dfs2(local + "(", left - 1, right, result);
	if (right > left) dfs2(local + ")", left , right - 1, result);
}

vector<string> Solution::generateParenthesis2(int n) {
	int left = n, right = n;
	vector<string> result;
	dfs2("", n, n, result);
	return result;
}
