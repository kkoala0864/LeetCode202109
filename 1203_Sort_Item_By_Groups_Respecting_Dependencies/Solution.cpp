#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::unordered_set;

vector<int> Solution::sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
	for (auto &g : group)
		if (g == -1)
			g = m++;

	vector<vector<int>> gb(m, vector<int>());
	vector<vector<int>> ib(n, vector<int>());
	vector<int> ibCnt(n, 0);
	vector<int> gbCnt(m, 0);

	for (int i = 0; i < n; ++i) {
		int ig = group[i];
		for (const auto &e : beforeItems[i]) {
			int bg = group[e];
			if (ig == bg) {
				++ibCnt[i];
				ib[e].emplace_back(i);
			} else {
				++gbCnt[ig];
				gb[bg].emplace_back(ig);
			}
		}
	}
	vector<vector<int>> r(m, vector<int>());
	vector<int> result;

	queue<int> iq, gq;
	for (int i = 0; i < n; ++i)
		if (ibCnt[i] == 0)
			iq.emplace(i);
	while (!iq.empty()) {
		int cur = iq.front();
		iq.pop();
		r[group[cur]].emplace_back(cur);
		for (const auto &ni : ib[cur]) {
			--ibCnt[ni];
			if (ibCnt[ni] == 0)
				iq.emplace(ni);
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << i << " | ";
		for (const auto &j : r[i])
			cout << j << " ";
		cout << endl;
	}

	for (int i = 0; i < m; ++i)
		if (gbCnt[i] == 0)
			gq.emplace(i);
	while (!gq.empty()) {
		int cur = gq.front();
		gq.pop();
		for (const auto &v : r[cur])
			result.emplace_back(v);
		for (const auto &ng : gb[cur]) {
			--gbCnt[ng];
			if (gbCnt[ng] == 0)
				gq.emplace(ng);
		}
	}

	return result.size() == n ? result : vector<int>();
}
