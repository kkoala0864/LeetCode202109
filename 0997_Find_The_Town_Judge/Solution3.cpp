#include <Solution.h>
#include <iostream>

int Solution::findJudge3(int n, vector<vector<int>> &trust) {
	vector<int> trustCnt(n, 0), beTrustCnt(n, 0);
	for (const auto &t : trust) {
		++trustCnt[t[0] - 1];
		++beTrustCnt[t[1] - 1];
	}

	for (int i = 0; i < n; ++i) {
		if (trustCnt[i] == 0 && beTrustCnt[i] == n - 1)
			return i + 1;
	}
	return -1;
}
