#include <Solution.h>

vector<int> Solution::shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
	vector<vector<int>> cIdxs(3, vector<int>());
	for (int i = 0 ; i < colors.size() ; ++i) {
		cIdxs[colors[i] - 1].emplace_back(i);
	}

	vector<int> result;
	for (const auto& q : queries) {
		int i = q[0];
		int c = q[1] - 1;
		if (colors[i] == (c + 1)) {
			result.emplace_back(0);
			continue;
		}
		if (cIdxs[c].empty()) {
			result.emplace_back(-1);
			continue;
		}
		int idx = upper_bound(cIdxs[c].begin(), cIdxs[c].end(), i) - cIdxs[c].begin();

		int v = INT_MAX;
		if (idx < cIdxs[c].size()) {
			v = min(v, abs(i - cIdxs[c][idx]));
		}
		if (idx > 0) {
			--idx;
			v = min(v, abs(i - cIdxs[c][idx]));
		}
		result.emplace_back(v);
	}
	return result;
}
