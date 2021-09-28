#include <Solution.h>
#include <iostream>
#include <climits>

// Clarify : how many course does each course depend on ?

bool Solution::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	if (prerequisites.empty()) return true;
	vector<bool> finish(numCourses, true);
	vector<int> check;

	vector<vector<int>> depends(numCourses, vector<int>());
	for (const auto& iter : prerequisites) {
		if (iter[0] == iter[1]) return false;
		depends[iter[0]].emplace_back(iter[1]);
		if (finish[iter[0]]) check.emplace_back(iter[0]);
		finish[iter[0]] = false;
	}

	vector<int> nextCheck;
	int size = INT_MAX;
	while (!check.empty()) {
		int next = check.back();
		check.pop_back();
		if (finish[next]) continue;

		bool local = true;
		for (const auto& iter : depends[next]) local = local & finish[iter];
		if (local) finish[next] = true;
		else nextCheck.emplace_back(next);

		if (check.empty()) {
			if (size == nextCheck.size()) break;
			size = nextCheck.size();
			check = move(nextCheck);
		}
	}

	return size == 0;
}
