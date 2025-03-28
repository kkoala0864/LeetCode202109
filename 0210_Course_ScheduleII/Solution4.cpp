#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::findOrder4(int numCourses, vector<vector<int>> &prerequisites) {
	vector<vector<int>> indegree(numCourses, vector<int>());
	vector<int> depCnt(numCourses, 0);

	for (const auto &p : prerequisites) {
		indegree[p[1]].emplace_back(p[0]);
		++depCnt[p[0]];
	}

	queue<int> que;
	vector<int> result;
	for (int i = 0; i < numCourses; ++i) {
		if (depCnt[i] == 0) {
			que.emplace(i);
			result.emplace_back(i);
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto &v : indegree[cur]) {
			--depCnt[v];
			if (depCnt[v] == 0) {
				que.emplace(v);
				result.emplace_back(v);
			}
		}
	}
	return result.size() == numCourses ? result : vector<int>();
}
