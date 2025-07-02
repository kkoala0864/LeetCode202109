#include <Solution.h>

int getBStr(int v) {
	int ret = 0;
	while (v > 0) {
		++ret;
		v = v >> 1;
	}
	return ret;
}

void dfs(vector<pair<int, int>>& bs, int idx, int& result) {
	if (idx == bs.size()) {
		int cnt = 0;
		int sum = 0;
		for (const auto& v : bs) {
			sum = sum << v.second;
			sum += v.first;
		}
		result = max(result, sum);
	}
	for (int i = idx ; i <= 2 ; ++i) {
		swap(bs[idx], bs[i]);
		dfs(bs, idx + 1, result);
		swap(bs[idx], bs[i]);
	}
}

int Solution::maxGoodNumber(vector<int>& nums) {
	vector<pair<int, int>> bs;
	for (const auto& v : nums) {
		bs.emplace_back(pair<int, int>(v, getBStr(v)));
	}
	int result = 0;
	dfs(bs, 0, result);
	return result;
}
