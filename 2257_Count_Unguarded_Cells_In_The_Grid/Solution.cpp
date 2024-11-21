#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

void oper(int& mask, int& v) {
	if (v == 2) {
		mask = 1;
	} else if (v == 3) {
		mask = 0;
	} else {
		if (mask == 0) return;
		v = 1;
	}
}

int Solution::countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
	vector<vector<int>> g(m, vector<int>(n, 0));
	vector<vector<bool>> dir(guards.size(), vector<bool>(4, false));

	for (const auto& w : walls) g[w[0]][w[1]] = 3;
	for (const auto& u : guards) g[u[0]][u[1]] = 2;

	for (int i = 0 ; i < m ; ++i) {
		int mask = 0;
		for (int j = 0 ; j < n ; ++j) {
			oper(mask, g[i][j]);
		}
		mask = 0;
		for (int j = n - 1 ; j >= 0 ; --j) {
			oper(mask, g[i][j]);
		}
	}
	for (int j = 0 ; j < n ; ++j) {
		int mask = 0;
		for (int i = 0 ; i < m ; ++i) {
			oper(mask, g[i][j]);
		}
		mask = 0;
		for (int i = m - 1 ; i >= 0 ; --i) {
			oper(mask, g[i][j]);
		}
	}
	int result = 0;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (g[i][j] == 0) ++result;
		}
	}

	return result;
}
