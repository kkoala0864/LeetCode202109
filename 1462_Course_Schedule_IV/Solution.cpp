#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_set>

using std::queue;
using std::unordered_set;

vector<bool> Solution::checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
	vector<vector<int>> od(numCourses, vector<int>());
	vector<int> idc(numCourses, 0);

	for (const auto &p : prerequisites) {
		od[p[0]].emplace_back(p[1]);
		++idc[p[1]];
	}
	vector<unordered_set<int>> preNode(numCourses, unordered_set<int>());
	queue<int> que;
	for (int i = 0; i < numCourses; ++i) {
		if (idc[i] == 0)
			que.emplace(i);
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto &n : od[cur]) {
			for (const auto &pn : preNode[cur]) {
				preNode[n].emplace(pn);
			}
			preNode[n].emplace(cur);
			--idc[n];
			if (idc[n] == 0)
				que.emplace(n);
		}
	}
	vector<bool> result;
	for (const auto &q : queries) {
		result.push_back(preNode[q[1]].count(q[0]));
	}
	return result;
}
