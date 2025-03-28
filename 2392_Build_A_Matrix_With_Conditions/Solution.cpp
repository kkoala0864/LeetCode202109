#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> topology(vector<vector<int>> conditions, int k) {
	vector<vector<int>> od(k, vector<int>());
	vector<int> idc(k, 0);
	for (const auto &c : conditions) {
		od[c[0] - 1].emplace_back(c[1] - 1);
		++idc[c[1] - 1];
	}

	queue<int> que;
	for (int i = 0; i < idc.size(); ++i) {
		if (idc[i] == 0)
			que.emplace(i);
	}

	vector<int> result;
	while (!que.empty()) {
		int curV = que.front();
		que.pop();
		result.emplace_back(curV);
		for (const auto &n : od[curV]) {
			--idc[n];
			if (idc[n] == 0)
				que.emplace(n);
		}
	}
	return result.size() == k ? result : vector<int>();
}

vector<vector<int>> Solution::buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions) {
	auto rl = topology(rowConditions, k);
	auto cl = topology(colConditions, k);

	if (rl.empty() || cl.empty())
		return {};

	vector<vector<int>> result(k, vector<int>(k, 0));

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			if (rl[i] == cl[j]) {
				result[i][j] = rl[i] + 1;
			}
		}
	}
	return result;
}
