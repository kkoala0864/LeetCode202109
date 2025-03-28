#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::numPairsDivisibleBy60(vector<int> &time) {
	if (time.size() < 2)
		return 0;

	int cnt = 0;
	vector<int> uMap(60, 0);
	for (const auto &iter : time) {
		int rp = (60 - (iter % 60)) % 60;
		if (uMap[rp] > 0)
			cnt += uMap[rp];
		++uMap[iter % 60];
	}

	return cnt;
}
