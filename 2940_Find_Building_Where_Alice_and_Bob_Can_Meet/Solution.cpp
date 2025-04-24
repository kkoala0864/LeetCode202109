#include <Solution.h>
#include <iostream>
#include <algorithm>

// idx left value < idx right value = idx right
// idx left value >= idx right value = find most left build start from right + 1 which height is taller than idx left value
vector<int> Solution::leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
	for (int i = 0 ; i < queries.size() ; ++i) {
		sort(queries[i].begin(), queries[i].end());
		queries[i].emplace_back(i);
	}
	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
	};
	sort(queries.begin(), queries.end(), cmp);

	int maxV = 0;
	for (const auto& v : heights) maxV = max(maxV, v);
	++maxV;

	BTree* bt = new BTree();

	int hIdx = heights.size() - 1;

	vector<int> result(queries.size(), -1);
	for (int i = queries.size() - 1 ; i >= 0 ; --i) {
		int lv = heights[queries[i][0]];
		int rv = heights[queries[i][1]];
		int ri = queries[i][2];

		if (queries[i][0] == queries[i][1] || lv < rv) {
			result[ri] = queries[i][1];
			continue;
		}

		while (hIdx >= 0 && hIdx > (queries[i][1])) {
			bt->update(heights[hIdx], hIdx, bt, 0, maxV);
			--hIdx;
		}
		int ret = bt->query(lv + 1, maxV, bt, 0, maxV);
		result[queries[i][2]] = ret == INT_MAX ? -1 : ret;
	}
	return result;
}
