#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::queue;
using std::max;
using std::cout;
using std::endl;

int getCenterLen(vector<vector<int>>& e1, int& diameter) {
	int n = e1.size() + 1;
	if (n < 3) return n;
	vector<int> idc(n, 0);
	vector<vector<int>> od(n, vector<int>());

	for (const auto& e : e1) {
		++idc[e[0]];
		++idc[e[1]];
		od[e[0]].emplace_back(e[1]);
		od[e[1]].emplace_back(e[0]);
	}

	queue<int> que, next;
	int result = 0;

	for (int i = 0 ; i < n ; ++i) if (idc[i] == 1) que.emplace(i);

	int lsize = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		++lsize;

		for (const auto& nn : od[cur]) {
			--idc[nn];
			if (idc[nn] == 1) {
				next.emplace(nn);
			}
		}

		if (que.empty()) {
			que = move(next);
			++result;
			if (!que.empty()) {
				lsize = 0;
				diameter += 2;
			}
		}
	}
	diameter += lsize;
	return lsize == 2 ? result + 1 : result;
}

int Solution::minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
	int d1 = 0, d2 = 0;
	int l1 = getCenterLen(edges1, d1);
	int l2 = getCenterLen(edges2, d2);
	return max({l1 + l2 - 1, d1 - 1, d2 - 1});
}
