#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

void dfs(vector<vector<string>> &result, int r, vector<bool> &c, unordered_set<int> &ls, unordered_set<int> &rs, vector<string> &local) {
	int n = c.size();
	if (r == c.size()) {
		result.emplace_back(local);
		return;
	}

	for (int j = 0; j < c.size(); ++j) {
		if (c[j])
			continue;
		if (ls.count(r - j))
			continue;
		int rsV = n - 1 - r - j;
		if (rs.count(rsV))
			continue;

		c[j] = true;
		ls.emplace(r - j);
		rs.emplace(rsV);
		local[r][j] = 'Q';

		dfs(result, r + 1, c, ls, rs, local);

		c[j] = false;
		ls.erase(r - j);
		rs.erase(rsV);
		local[r][j] = '.';
	}
}

vector<vector<string>> Solution::solveNQueens2(int n) {
	vector<bool> c(n, false);
	unordered_set<int> ls, rs;

	vector<vector<string>> result;
	vector<string> local(n, string(n, '.'));
	dfs(result, 0, c, ls, rs, local);
	return result;
}
