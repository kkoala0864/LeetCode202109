#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::unordered_set;
using std::max;

int Solution::maximalNetworkRank3(int n, vector<vector<int>>& roads) {
	vector<vector<int>> edge(n, vector<int>(n, 0));
	vector<int> outdegree(n, 0);

	for (const auto& r : roads) {
		++edge[r[0]][r[1]];
		++edge[r[1]][r[0]];
		++outdegree[r[0]];
		++outdegree[r[1]];
	}
	int result = 0;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = i + 1 ; j < n ; ++j) {
			result = max(result, outdegree[i] + outdegree[j] - edge[i][j]);
		}
	}
	return result;
}
