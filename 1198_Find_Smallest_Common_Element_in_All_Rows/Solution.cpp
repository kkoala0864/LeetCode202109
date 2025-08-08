#include <Solution.h>

int Solution::smallestCommonElement(vector<vector<int>> &mat) {
	for (const auto& v : mat[0]) {
		int i = 1;
		for (; i < mat.size() ; ++i) {
			int idx = lower_bound(mat[i].begin(), mat[i].end(), v) - mat[i].begin();
			if (idx == mat[i].size()) break;
			if (mat[i][idx] != v) break;
		}
		if (i == mat.size()) return v;
	}
	return -1;
}
