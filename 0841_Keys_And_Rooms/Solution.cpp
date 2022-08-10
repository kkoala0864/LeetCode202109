#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

bool Solution::canVisitAllRooms(vector<vector<int>>& rooms) {
	vector<bool> unlock(rooms.size(), false);
	int cnt = rooms.size();

	queue<int> q;
	q.emplace(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (unlock[cur]) continue;
		unlock[cur] = true;
		--cnt;

		for (int i = 0 ; i < rooms[cur].size() ; ++i) {
			if (unlock[rooms[cur][i]]) continue;
			q.emplace(rooms[cur][i]);
		}
	}
	return cnt == 0;
}
