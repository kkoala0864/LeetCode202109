#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::findMinHeightTrees2(int n, vector<vector<int>>& edges) {
	if (n == 1) return vector<int>(1, 0);
	vector<vector<int>> relation(n, vector<int>());
	vector<int> cnt(n, 0);

	for (const auto& iter : edges) {
		++cnt[iter[0]];
		++cnt[iter[1]];
		relation[iter[0]].emplace_back(iter[1]);
		relation[iter[1]].emplace_back(iter[0]);
	}

	queue<int> cur, next;
	vector<int> result;
	for (int i = 0 ; i < n ; ++i) {
		if (cnt[i] == 1) cur.emplace(i);
	}

	while (!cur.empty()) {
		result.clear();
		while (!cur.empty()) {
			int node = cur.front();
			cur.pop();
			result.emplace_back(node);
			--cnt[node];
			for (const auto& iter : relation[node]) {
				--cnt[iter];
				if (cnt[iter] == 1) next.emplace(iter);
			}
		}
		cur = move(next);
	}
	return result;
}
