#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

void outputResult(vector<int> &list, vector<vector<string>> &result) {
	vector<string> local;
	for (int row = 0; row < list.size(); ++row) {
		int colQ = list[row];
		string tmp;
		for (int col = 0; col < list.size(); ++col) {
			if (col == colQ)
				tmp.push_back('Q');
			else
				tmp.push_back('.');
		}
		local.emplace_back(tmp);
	}
	result.emplace_back(local);
}

void dfs(int row, int n, vector<int> &list, vector<vector<string>> &result) {
	for (int col = 0; col < n; ++col) {
		int lrow = 0;
		for (; lrow < list.size(); ++lrow) {
			if (list[lrow] == col || abs(row - lrow) == abs(col - list[lrow])) {
				break;
			}
		}
		if (lrow != row)
			continue;
		list.emplace_back(col);
		if (row == n - 1)
			outputResult(list, result);
		else
			dfs(row + 1, n, list, result);
		list.pop_back();
	}
}

vector<vector<string>> Solution::solveNQueens(int n) {
	vector<vector<string>> result;
	vector<int> list;
	dfs(0, n, list, result);
	return result;
}
