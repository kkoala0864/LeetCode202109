#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

bool Solution::canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> depend(numCourses, vector<int>());
	vector<int> depCnt(numCourses, 0);

	for (const auto& iter : prerequisites) {
		depend[iter[1]].emplace_back(iter[0]);
		++depCnt[iter[0]];
	}

	queue<int> course;
	for (int i = 0 ; i < depCnt.size() ; ++i) {
		if (depCnt[i] == 0) course.emplace(i);
	}

	int finishCnt = 0;
	while (!course.empty()) {
		int cur = course.front();
		course.pop();
		++finishCnt;
		for (const auto& iter : depend[cur]) {
			--depCnt[iter];
			if (depCnt[iter] == 0) {
				course.emplace(iter);
			}
		}
	}
	return finishCnt == numCourses;
}
