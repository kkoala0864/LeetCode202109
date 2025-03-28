#include <Solution.h>
#include <iostream>

int Solution::kthSmallest2(vector<vector<int>> &matrix, int k) {
	int l = matrix[0][0];
	int r = matrix.back().back();
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);
		int total = 0;
		for (const auto &m : matrix) {
			total += (upper_bound(m.begin(), m.end(), mid) - m.begin());
		}
		if (total >= k)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}
