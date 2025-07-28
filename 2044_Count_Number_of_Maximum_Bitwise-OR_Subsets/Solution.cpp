#include <Solution.h>

void dfs(int idx, vector<pair<int, int>>& list, int cnt, int val, int& maxVal, int& result) {
	if (idx == list.size()) {
		if (val == maxVal) result += cnt;
		else if (val > maxVal) {
			maxVal = val;
			result = cnt;
		}
		return;
	}

	dfs(idx + 1, list, cnt * list[idx].second, val | list[idx].first, maxVal, result);
	dfs(idx + 1, list, cnt, val, maxVal, result);
}

int Solution::countMaxOrSubsets(vector<int>& nums) {
	int result = 0;
	int maxVal = 0;
	unordered_map<int, int> m;
	for (const auto& v : nums) ++m[v];
	vector<pair<int, int>> list;
	for (const auto& e : m) {
		list.emplace_back(pair<int, int>(e.first, (1 << e.second) - 1));
	}

	dfs(0, list, 1, 0, maxVal, result);
	return result;
}
