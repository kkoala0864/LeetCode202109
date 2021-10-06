#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	vector<int> cnt(numCourses, 0);
	vector<vector<int>> dep(numCourses, vector<int>());
	vector<int> result;

	for (const auto& iter : prerequisites) {
		++cnt[iter[0]];
		dep[iter[1]].emplace_back(iter[0]);
	}

	queue<int> que;
	for (int i = 0 ; i < numCourses ; ++i) if (cnt[i] == 0) que.emplace(i);

	while (!que.empty()) {
		int finish = que.front();
		que.pop();
		result.emplace_back(finish);

		for (const auto& iter : dep[finish]) {
			--cnt[iter];
			if (cnt[iter] == 0) que.emplace(iter);
		}
	}
	return result.size() == numCourses ? result : vector<int>();
}
