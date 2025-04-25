#include <Solution.h>
#include <iostream>

int findPeak(vector<int>& v) {
	if (v.size() == 1) return 0;

	int l = 0, r = v.size() - 1;
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		if (mid == 0) {
			if (v[mid] < v[mid+1]) {
				l = mid + 1;
			} else {
				r = mid;
			}
		} else if (mid == v.size() - 1) {
			if (v[mid - 1] > v[mid]) {
				r = mid - 1;
			} else {
				l = mid;
			}
		} else {
			if (v[mid] < v[mid+1]) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
	}
	return l;
}

vector<int> Solution::findPeakGrid(vector<vector<int>>& mat) {
	for (int i = 0 ; i < mat.size() ; ++i) {
		int idx = findPeak(mat[i]);
		if (i > 0 && mat[i][idx] < mat[i-1][idx]) continue;
		if (i < mat.size() - 1 && mat[i][idx] < mat[i+1][idx]) continue;
		return vector<int>({i, idx});
	}

	for (int i = 0 ; i < mat[0].size() ; ++i) {
		vector<int> tmp(mat.size(), 0);
		for (int j = 0 ; j < mat.size() ; ++j) {
			tmp[j] = mat[j][i];
		}
		int idx = findPeak(tmp);
		if (i > 0 && mat[idx][i] < mat[idx][i-1]) continue;
		if (i < mat[0].size() - 1 && mat[idx][i] < mat[idx][i+1]) continue;
		return vector<int>({idx, i});
	}
	return vector<int>();
}
