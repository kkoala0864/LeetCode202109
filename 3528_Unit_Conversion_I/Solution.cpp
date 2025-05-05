#include <Solution.h>

vector<int> Solution::baseUnitConversions(vector<vector<int>>& conversions) {
	queue<pair<int, long long>> que;

	vector<vector<pair<int, long long>>> connect(conversions.size() + 1, vector<pair<int, long long>>());

	for (const auto& c : conversions) {
		connect[c[0]].emplace_back(pair<int, long long>(c[1], c[2]));
	}

	que.emplace(pair<int, long long>(0, 1));
	vector<int> result(conversions.size() + 1, 0);
	long long mod = 1e9 + 7;

	while (!que.empty()) {
		int uid = que.front().first;
		long long unit = que.front().second;

		result[uid] = unit;

		que.pop();
		for (const auto& nu : connect[uid]) {
			que.emplace(pair<int, long long>(nu.first, nu.second * unit % mod));
		}
	}
	return result;

}
