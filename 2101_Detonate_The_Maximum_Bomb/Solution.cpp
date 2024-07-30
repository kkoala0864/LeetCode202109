#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using std::queue;
using std::unordered_set;
using std::max;

void tryDetonate(int start, vector<vector<int>>& connect, int& result) {
	unordered_set<int> bomb;
	queue<int> que;
	que.emplace(start);
	bomb.emplace(start);
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto& n : connect[cur]) {
			if (bomb.count(n)) continue;
			bomb.emplace(n);
			que.emplace(n);
		}
	}
	result = max(result, (int)bomb.size());
}

double getDis(long long x1, long long y1, long long x2, long long y2) {
	long long v = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return sqrt(v);
}

int Solution::maximumDetonation(vector<vector<int>>& bombs) {
	vector<vector<int>> connect(bombs.size(), vector<int>());

	for (int i = 0 ; i < bombs.size() ; ++i) {
		for (int j = i + 1 ; j < bombs.size() ; ++j) {
			double dis = getDis(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]);
			if ((double)bombs[i][2] >= dis) {
				connect[i].emplace_back(j);
			}
			if ((double)bombs[j][2] >= dis) {
				connect[j].emplace_back(i);
			}
		}
	}

	int result = 0;
	for (int i = 0 ; i < bombs.size() ; ++i) {
		tryDetonate(i, connect, result);
	}
	return result;
}
