#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

bool Solution::canVisitAllRooms2(vector<vector<int>>& rooms) {
	queue<int> que;
	int cnt = 0;
	vector<bool> open(rooms.size(), false);
	for (int i = 0 ; i < rooms.size() ; ++i) {
		if (rooms.empty()) ++cnt;
	}
	open[0] = true;
	que.emplace(0);
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		++cnt;
		for (const auto& k : rooms[cur]) {
			if (open[k]) continue;
			open[k] = true;
			que.emplace(k);
		}
	}
	return cnt == rooms.size();
}
