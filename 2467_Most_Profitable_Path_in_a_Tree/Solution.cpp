#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::max;

bool gotoZero(vector<vector<int>> &od, int cur, vector<int> &bStep, int step, int prev) {
	if (cur == 0) {
		bStep[cur] = step;
		return true;
	}

	for (const auto &n : od[cur]) {
		if (n == prev)
			continue;
		if (gotoZero(od, n, bStep, step + 1, cur)) {
			bStep[cur] = step;
			return true;
		}
	}
	return false;
}

void getVal(vector<vector<int>> &od, vector<int> &bStep, vector<int> &amount, int time, int cur, int prev, int profit, int &result) {
	int cp = amount[cur];
	if (bStep[cur] != -1) {
		if (bStep[cur] < time) {
			cp = 0;
		} else if (bStep[cur] == time) {
			cp = cp >> 1;
		}
	}

	profit += cp;
	if (od[cur].size() == 1 && cur != 0) {
		result = max(result, profit);
		return;
	}
	for (const auto &n : od[cur]) {
		if (n == prev)
			continue;
		getVal(od, bStep, amount, time + 1, n, cur, profit, result);
	}
}

int Solution::mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount) {
	vector<vector<int>> od(edges.size() + 1, vector<int>());

	for (const auto &e : edges) {
		od[e[0]].emplace_back(e[1]);
		od[e[1]].emplace_back(e[0]);
	}

	vector<int> bStep(edges.size() + 1, -1);
	gotoZero(od, bob, bStep, 0, -1);

	int result = INT_MIN;
	getVal(od, bStep, amount, 0, 0, -1, 0, result);
	return result;
}
