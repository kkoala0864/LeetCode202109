#include <Solution.h>
#include <iostream>

bool Solution::areSimilar(vector<vector<int>>& mat, int k) {
	int m = mat.size();
	int n = mat[0].size();
	k %= n;

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (i & 1) {
				if (mat[i][j] == mat[i][(j+k) % n]) continue;
				else return false;
			} else {
				if (mat[i][j] == mat[i][(j-k + n) % n]) continue;
				else return false;
			}
		}
	}
	return true;
}

