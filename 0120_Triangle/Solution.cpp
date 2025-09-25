#include <Solution.h>

int Solution::minimumTotal(vector<vector<int>> &triangle) {
	int m = triangle.size();
	int n = triangle[0].size();

	for (int i = 1 ; i < m ; ++i) {
		for (int j = 0 ; j < triangle[i].size() ; ++j) {
			int v = INT_MAX;
			if (j < triangle[i].size() - 1) {
				v = min(v, triangle[i-1][j]);
			}
			if (j > 0) {
				v = min(v, triangle[i-1][j-1]);
			}
			triangle[i][j] += v;
		}
	}
	int result = INT_MAX;
	for (const auto& v : triangle.back()) {
		result = min(result, v);
	}
	return result;
}
