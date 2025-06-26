#include <Solution.h>

int getCnt(int v) {
	int ret = 0;
	while (v > 0) {
		++ret;
		v &= (v-1);
	}
	return ret;
}

int Solution::maximumRequests(int n, vector<vector<int>>& requests) {
	int result = 0;
	int size = requests.size();
	for (int i = 0 ; i < (1 << size) ; ++i) {
		int cnt = getCnt(i);
		if (cnt < result) continue;
		vector<int> delta(n, 0);
		for (int j = 0 ; j < size ; ++j) {
			if (((1 << j) & i) == 0) continue;
			--delta[requests[j][0]];
			++delta[requests[j][1]];
		}
		int k = 0;
		for (; k < n ; ++k) {
			if (delta[k] == 0) continue;
			break;
		}
		if (k == n) {
			result = max(cnt, result);
		}
	}

	return result;
}
