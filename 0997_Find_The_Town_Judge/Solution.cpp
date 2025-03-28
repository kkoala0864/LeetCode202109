#include <Solution.h>
#include <iostream>

int Solution::findJudge(int n, vector<vector<int>> &trust) {
	if (n == 1)
		return n;
	vector<int> in(n + 1, 0), out(n + 1, 0);
	for (const auto &iter : trust) {
		++out[iter[0]];
		++in[iter[1]];
	}

	int judge = -1;
	for (int i = 1; i <= n; ++i) {
		if (out[i] == 0 && in[i] == (n - 1)) {
			if (judge == -1)
				judge = i;
			else
				return -1;
		}
	}
	return judge;
}
