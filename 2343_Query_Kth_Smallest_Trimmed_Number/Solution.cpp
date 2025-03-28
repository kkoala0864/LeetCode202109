#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::pair;
using std::sort;

void rSort(vector<pair<string, int>> &vec) {
	vector<vector<pair<string, int>>> sort(10, vector<pair<string, int>>());
	vector<pair<string, int>> next;
	int n = vec[0].first.size();
	for (int i = n - 1; i >= 0; --i) {
		for (const auto &v : vec) {
			sort[v.first[i] - '0'].emplace_back(v);
		}
		for (int j = 0; j < 10; ++j) {
			for (auto &v : sort[j])
				next.emplace_back(v);
			if (!sort[j].empty())
				sort[j].clear();
		}
		vec = move(next);
	}
}

vector<int> Solution::smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
	int n = nums[0].size();
	vector<vector<pair<string, int>>> cache(n + 1, vector<pair<string, int>>());

	auto cmp = [](pair<string, int> &lhs, pair<string, int> &rhs) {
		return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first;
	};

	vector<int> result;
	for (const auto &q : queries) {
		if (cache[q[1]].empty()) {
			vector<pair<string, int>> l;
			for (int i = 0; i < nums.size(); ++i) {
				string substr = nums[i].substr(n - q[1], q[1]);
				l.push_back({substr, i});
			}
			sort(l.begin(), l.end(), cmp);
			result.emplace_back(l[q[0] - 1].second);
			cache[q[1]] = move(l);
		} else {
			result.emplace_back(cache[q[1]][q[0] - 1].second);
		}
	}
	return result;
}
