#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::findOrder2(int numCourses, vector<vector<int>> &prerequisites) {
	vector<vector<int>> dep(numCourses, vector<int>());
	vector<int> depCnt(numCourses, 0);

	for (const auto &iter : prerequisites) {
		dep[iter[1]].emplace_back(iter[0]);
		++depCnt[iter[0]];
	}

	queue<int> cur;
	for (int i = 0; i < depCnt.size(); ++i) {
		if (depCnt[i] == 0)
			cur.emplace(i);
	}

	vector<int> result;
	while (!cur.empty()) {
		int course = cur.front();
		result.emplace_back(course);
		cur.pop();
		for (const auto &iter : dep[course]) {
			--depCnt[iter];
			if (depCnt[iter] == 0)
				cur.emplace(iter);
		}
	}

	return result.size() == numCourses ? result : vector<int>();
}
