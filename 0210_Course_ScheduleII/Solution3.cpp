#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::findOrder3(int numCourses, vector<vector<int>>& prerequisites) {
	vector<int> result;
	vector<vector<int>> dep(numCourses, vector<int>());
	vector<int> cnt(numCourses, 0);
	queue<int> que;

	for (const auto& pre : prerequisites) {
		dep[pre[1]].emplace_back(pre[0]);
		++cnt[pre[0]];
	}

	for (int i = 0 ; i < cnt.size() ; ++i) if (cnt[i] == 0) que.emplace(i);

	while (!que.empty()) {
		int course = que.front();
		que.pop();
		result.emplace_back(course);

		for (const auto& iter : dep[course]) {
			--cnt[iter];
			if (cnt[iter] == 0) que.emplace(iter);
		}
	}

	return result.size() == numCourses ? result : vector<int>();
}
