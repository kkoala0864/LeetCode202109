#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
	int m = matrix.size(), n = matrix[0].size();
	for (int i = 0; i < m; ++i)
		for (int j = 1; j < n; ++j)
			matrix[i][j] += matrix[i][j - 1];

	int result = 0;
	unordered_map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			cnt = {{0, 1}};
			int cur = 0;
			for (int k = 0; k < m; ++k) {
				cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
				result += cnt.find(cur - target) != cnt.end() ? cnt[cur - target] : 0;
				++cnt[cur];
			}
		}
	}
	return result;
}
