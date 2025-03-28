#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

int Solution::minimumSemesters(int n, vector<vector<int>> &relations) {
	vector<vector<int>> outdegree(n + 1, vector<int>());
	vector<int> indegree(n + 1, 0);

	for (const auto &relation : relations) {
		outdegree[relation[0]].emplace_back(relation[1]);
		++indegree[relation[1]];
	}

	queue<int> que, next;
	int result = 0, courseCnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) {
			que.emplace(i);
			++courseCnt;
		}
	}
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto &course : outdegree[cur]) {
			--indegree[course];
			if (indegree[course] == 0) {
				next.emplace(course);
				++courseCnt;
			}
		}

		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return courseCnt == n ? result : -1;
}
