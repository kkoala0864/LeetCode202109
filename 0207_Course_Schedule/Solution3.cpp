#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

bool Solution::canFinish3(int numCourses, vector<vector<int>> &prerequisites) {
	vector<int> dependence(numCourses, 0);
	vector<vector<int>> depCourse(numCourses, vector<int>());

	for (const auto &pre : prerequisites) {
		++dependence[pre[0]];
		depCourse[pre[1]].emplace_back(pre[0]);
	}

	queue<int> que;
	for (int i = 0; i < dependence.size(); ++i) {
		if (dependence[i] == 0)
			que.emplace(i);
	}

	int result = 0;
	while (!que.empty()) {
		int course = que.front();
		que.pop();
		++result;
		for (const auto &iter : depCourse[course]) {
			--dependence[iter];
			if (dependence[iter] == 0)
				que.emplace(iter);
		}
	}
	return result == numCourses;
}
