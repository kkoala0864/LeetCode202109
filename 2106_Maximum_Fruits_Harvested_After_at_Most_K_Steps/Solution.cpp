#include <Solution.h>

int Solution::maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

	int size = fruits.size();
	vector<int> idxs;
	vector<int> amounts;
	for (const auto& f : fruits) {
		idxs.emplace_back(f[0]);
		amounts.emplace_back(amounts.empty() ? f[1] : amounts.back() + f[1]);
	}

	int result = 0;
	int si = lower_bound(idxs.begin(), idxs.end(), startPos) - idxs.begin();
	if (si == idxs.size()) --si;

	if (idxs[si] >= startPos) {
		for (int i = si ; i < size ; ++i) {
			if ((startPos + k) < idxs[i]) break;

			int folds = idxs[i] - startPos;
			int li = min(startPos, idxs[i] - (k - folds));
			int idx = lower_bound(idxs.begin(), idxs.end(), li) - idxs.begin();

			int cur = amounts[i];
			if (idx > 0) cur -= amounts[idx-1];
			result = max(result, cur);
		}
	}
	if (idxs[si] >= startPos) --si;
	for (int i = si ; i >= 0 ; --i) {
		if (abs(startPos - idxs[i]) > k) break;

		int folds = startPos - idxs[i];
		int ri = max(startPos, idxs[i] + (k - folds));
		int idx = upper_bound(idxs.begin(), idxs.end(), ri) - idxs.begin();
		--idx;
		int cur = amounts[idx];
		if (i > 0) cur -= amounts[i-1];
		result = max(result, cur);
	}
	return result;

}
