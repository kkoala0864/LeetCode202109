#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minSwaps(vector<int>& data) {
	int cnt = 0;
	for (const auto& v : data) cnt += v;

	int minZeroCnt = cnt;
	int cur = 0;
	for (int i = 0 ; i < data.size() ; ++i) {
		if (data[i] == 0) ++cur;
		if ((i - cnt) >= 0) {
			if (data[i-cnt] == 0) --cur;
		}

		if (i >= cnt-1) {
			minZeroCnt = min(minZeroCnt, cur);
		}
	}
	return minZeroCnt;
}

