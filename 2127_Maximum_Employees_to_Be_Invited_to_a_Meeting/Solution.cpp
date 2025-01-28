#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::max;
using std::queue;

int Solution::maximumInvitations(vector<int>& favorite) {
	int size = favorite.size();
	vector<int> id(size, 0);
	vector<int> depth(size, 1);
	vector<bool> visited(size, false);

	for (const auto& f : favorite) ++id[f];
	queue<int> que;
	for (int i = 0 ; i < size ; ++i) {
		if (id[i] == 0) {
			que.emplace(i);
			visited[i] = true;
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		--id[favorite[cur]];
		if (id[favorite[cur]] == 0) {
			visited[favorite[cur]] = true;
			que.emplace(favorite[cur]);
		}
		depth[favorite[cur]] = depth[cur] + 1;
	}

	int max_multiple_cycle = 0;
	int max_link = 0;
	for (int i = 0 ; i < size ; ++i) {
		if (visited[i]) continue;
		int cnt = 1;
		int cur = i;
		visited[i] = true;

		while (!visited[favorite[cur]]) {
			++cnt;
			cur = favorite[cur];
			visited[cur] = true;
		}
		if (cnt > 2) {
			max_multiple_cycle = max(max_multiple_cycle, cnt);
		} else if (cnt == 2) {
			max_link += (depth[cur] + depth[favorite[cur]]);
		}
	}

	return max(max_multiple_cycle, max_link);
}
