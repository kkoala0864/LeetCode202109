#include <Solution.h>

unordered_set<double> dfs(vector<double>& values, int start, int end) {
	unordered_set<double> result;

	if (start == end) {
		result.emplace(values[start]);
		return result;
	}

	for (int i = start ; i < end ; ++i) {
		auto pre = dfs(values, start, i);
		auto post = dfs(values, i + 1, end);

		for (const auto& v1 : pre) {
			for (const auto& v2 : post) {
				result.emplace(v1 + v2);
				result.emplace(v1 - v2);
				result.emplace(v1 * v2);
				if (v2 != 0) {
					result.emplace(v1 / v2);
				}
			}
		}
	}
	return result;
}

bool Solution::judgePoint24(vector<int>& cards) {
	vector<double> values;
	for (const auto& v : cards) {
		values.emplace_back(v);
	}
	sort(values.begin(), values.end());

	while (true) {
		auto result = dfs(values, 0, 3);
		for (const auto& v : result) {
			if (abs(v - 24) < 1e-10) return true;
		}

		if (!next_permutation(values.begin(), values.end())) break;
	}
	return false;
}
