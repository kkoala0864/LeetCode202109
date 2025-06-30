#include <Solution.h>

int Solution::shortestSequence(vector<int>& rolls, int k) {
	vector<vector<int>> idxs(k + 1, vector<int>());

	for (int i = 0 ; i < rolls.size() ; ++i) {
		idxs[rolls[i]].emplace_back(i);
	}

	int maxIdxs = -1;

	for (int sz = 1 ; sz <= rolls.size() ; ++sz) {
		vector<int> next(k + 1, -1);
		int nextMaxIdxs = -1;
		for (int i = 1 ; i <= k ; ++i) { // next value
			int ni = upper_bound(idxs[i].begin(), idxs[i].end(), maxIdxs) - idxs[i].begin();
			if (ni == idxs[i].size()) return sz;
			nextMaxIdxs = max(nextMaxIdxs, idxs[i][ni]);
		}
		maxIdxs = nextMaxIdxs;
	}
	return rolls.size() + 1;
}
