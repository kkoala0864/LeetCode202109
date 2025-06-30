#include <Solution.h>

bool Solution::mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
	vector<int> cur = {0, 0, 0};
	for (const auto& t : triplets) {
		int i = 0;
		for (; i < 3 ; ++i) {
			if (t[i] > target[i]) break;
		}
		if (i < 3) continue;
		for (i = 0 ; i < 3 ; ++i) {
			cur[i] = max(cur[i], t[i]);
		}
	}
	int i = 0;
	for (; i < 3 ; ++i) {
		if (cur[i] != target[i]) break;
	}
	return i == 3;
}
