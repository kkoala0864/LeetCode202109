#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

void dfs(vector<int> &cookies, int idx, vector<int> &local, int &result) {
	if (idx == cookies.size()) {
		int localMax = 0;
		for (const auto &val : local) {
			localMax = max(localMax, val);
		}
		result = min(result, localMax);
		return;
	}

	for (int i = 0; i < local.size(); ++i) {
		local[i] += cookies[idx];
		dfs(cookies, idx + 1, local, result);
		local[i] -= cookies[idx];
	}
}

int Solution::distributeCookies(vector<int> &cookies, int k) {
	int result = INT_MAX;
	vector<int> local(k, 0);
	dfs(cookies, 0, local, result);
	return result;
}
