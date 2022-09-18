#include <Solution.h>
#include <iostream>
#include <set>
#include <queue>
#include <unordered_map>

using std::set;
using std::queue;
using std::unordered_map;

vector<vector<string>> Solution::accountsMerge2(vector<vector<string>>& accounts) {
	unordered_map<string, vector<int>> uMap;
	for (int ai = 0 ; ai < accounts.size() ; ++ai) {
		for (int ei = 1 ; ei < accounts[ai].size() ; ++ei) {
			uMap[accounts[ai][ei]].emplace_back(ai);
		}
	}
	vector<int> visited(accounts.size(), false);
	vector<vector<string>> result;
	queue<int> que;
	for (int ai = 0 ; ai < accounts.size() ; ++ai) {
		if (visited[ai]) continue;
		que.emplace(ai);
		visited[ai] = true;
		set<string> local;

		while (!que.empty()) {
			int curAI = que.front();
			que.pop();
			for (int ei = 1 ; ei < accounts[curAI].size() ; ++ei) {
				local.emplace(accounts[curAI][ei]);
				for (const auto& nextIdx : uMap[accounts[curAI][ei]]) {
					if (visited[nextIdx]) continue;
					que.emplace(nextIdx);
					visited[nextIdx] = true;
				}
			}
		}
		vector<string> res(1, accounts[ai][0]);
		for (const auto& s : local) res.emplace_back(s);
		result.emplace_back(res);
	}
	return result;
}
