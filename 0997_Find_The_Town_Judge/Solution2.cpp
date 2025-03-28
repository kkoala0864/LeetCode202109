#include <Solution.h>
#include <iostream>

int Solution::findJudge2(int n, vector<vector<int>> &trust) {
	vector<int> id(n + 1, 0), od(n + 1, 0);

	for (const auto &t : trust) {
		++od[t[0]];
		++id[t[1]];
	}

	for (int i = 1; i <= n; ++i) {
		if (od[i] == 0 && id[i] == n - 1)
			return i;
	}
	return -1;
}
