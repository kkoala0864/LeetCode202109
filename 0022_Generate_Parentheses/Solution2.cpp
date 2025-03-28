#include <Solution.h>
#include <iostream>

void dfs2(int lcnt, int rcnt, string &local, vector<string> &result) {
	if (lcnt == 0 && rcnt == 0) {
		result.emplace_back(local);
		return;
	}

	if (lcnt > 0) {
		local.push_back('(');
		dfs2(lcnt - 1, rcnt, local, result);
		local.pop_back();
	}

	if (lcnt < rcnt) {
		local.push_back(')');
		dfs2(lcnt, rcnt - 1, local, result);
		local.pop_back();
	}
}

vector<string> Solution::generateParenthesis2(int n) {
	vector<string> result;
	string local;
	dfs2(n, n, local, result);
	return result;
}
