#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::queue;
using std::max;

int Solution::largestPathValue(string colors, vector<vector<int>>& edges) {
	int size = colors.size();

	vector<vector<int>> od(size, vector<int>());
	vector<int> iCnt(size, 0);
	vector<vector<int>> maxCnt(size, vector<int>(26, 0));

	queue<int> que;
	for (const auto& e : edges) {
		if (e[0] == e[1]) return -1;
		od[e[0]].emplace_back(e[1]);
		++iCnt[e[1]];
	}

	int cnt = 0;
	for (int i = 0 ; i < size ; ++i) {
		if (iCnt[i] == 0) {
			que.emplace(i);
			maxCnt[i][colors[i]-'a'] = 1;
			++cnt;
		}
	}
	if (que.empty()) return -1;

	int result = 1;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto& n : od[cur]) {
			vector<int> tmpCnt = maxCnt[cur];
			++tmpCnt[colors[n]-'a'];
			for (int i = 0 ; i < 26 ; ++i) {
				maxCnt[n][i] = max(maxCnt[n][i], tmpCnt[i]);
				result = max(maxCnt[n][i], result);
			}
			--iCnt[n];
			if (iCnt[n] == 0) {
				++cnt;
				if (cnt > size) return -1;
				que.emplace(n);
			}
		}
	}
	return cnt == size ? result : -1;
}
