#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::priority_queue;
using std::sort;

int Solution::scheduleCourse(vector<vector<int>> &courses) {
	auto cmp = [](vector<int> &lhs, vector<int> &rhs) { return lhs[1] < rhs[1]; };
	sort(courses.begin(), courses.end(), cmp);
	priority_queue<vector<int>> pq;

	int taken = 0;
	for (int i = 0; i < courses.size(); ++i) {
		if (courses[i][0] > courses[i][1])
			continue;
		pq.emplace(courses[i]);
		taken += courses[i][0];
		while (taken > courses[i][1]) {
			taken -= pq.top()[0];
			pq.pop();
		}
	}
	return pq.size();
}
