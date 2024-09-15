#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using std::unordered_map;
using std::queue;
using std::cout;
using std::endl;

string Solution::findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
	unordered_map<string, string> parent;

	for (const auto& r : regions) {
		for (int i = 1 ; i < r.size() ; ++i) {
			parent[r[i]] = r[0];
		}
	}

	unordered_map<string, int> cnt;
	queue<string> que;

	que.emplace(region1);
	que.emplace(region2);

	while (!que.empty()) {
		string cur = que.front();
		que.pop();

		++cnt[cur];
		if (cnt[cur] == 2) {
			return cur;
		}

		if (parent.count(cur)) que.emplace(parent[cur]);
	}

	return "";
}
