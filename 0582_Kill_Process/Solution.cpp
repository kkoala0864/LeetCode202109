#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using std::unordered_map;
using std::queue;

vector<int> Solution::killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
	unordered_map<int, vector<int>> child;
	for (int i = 0 ; i < pid.size() ; ++i) child[ppid[i]].emplace_back(pid[i]);

	queue<int> que;
	que.emplace(kill);
	vector<int> result;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		result.emplace_back(cur);
		for (const auto& v : child[cur]) {
			que.emplace(v);
		}
	}
	return result;
}
