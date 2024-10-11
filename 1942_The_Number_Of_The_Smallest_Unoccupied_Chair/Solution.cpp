#include <Solution.h>
#include <iostream>
#include <queue>
#include <map>

using std::priority_queue;
using std::map;

int Solution::smallestChair(vector<vector<int>>& times, int targetFriend) {
	int cur = 0;
	priority_queue<int, vector<int>, std::greater<int>> pq;

	vector<int> sit(times.size(), -1);

	map<int, vector<vector<int>>> time;

	for (int i = 0 ; i < times.size() ; ++i) {
		if (time.count(times[i][0]) == 0) {
			time[times[i][0]] = vector<vector<int>>(2, vector<int>());
		}
		if (time.count(times[i][1]) == 0) {
			time[times[i][1]] = vector<vector<int>>(2, vector<int>());
		}
		time[times[i][0]][0].emplace_back(i);
		time[times[i][1]][1].emplace_back(i);
	}

	for (const auto& e : time) {
		for (const auto& l : e.second[1]) {
			pq.emplace(sit[l]);
		}
		for (const auto& f : e.second[0]) {
			if (pq.empty()) {
				sit[f] = cur++;
			} else {
				sit[f] = pq.top();
				pq.pop();
			}
		}
		if (sit[targetFriend] != -1) return sit[targetFriend];
	}
	return -1;
}
