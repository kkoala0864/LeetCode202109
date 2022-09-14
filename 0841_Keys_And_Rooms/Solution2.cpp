#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

bool Solution::canVisitAllRooms2(vector<vector<int>>& rooms) {
	queue<int> que;
	vector<bool> visited(rooms.size(), false);

	que.emplace(0);
	int size = rooms.size() - 1;
	visited[0] = true;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto& r : rooms[cur]) {
			if (visited[r]) continue;
			visited[r] = true;
			--size;
			que.emplace(r);
		}
	}
	return size == 0;
}
