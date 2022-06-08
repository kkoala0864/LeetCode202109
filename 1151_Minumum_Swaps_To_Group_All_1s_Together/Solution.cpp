#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minSwaps(vector<int>& data) {
	int cnt = 0;
	for (const auto& val : data) if (val == 1) ++cnt;
	int result = data.size();
	int cur = 0;
	for (int i = 0 ; i < data.size() ; ++i) {
		if (data[i] == 1) ++cur;

		if (i >= (cnt - 1)) {
			result = min(result, cnt - cur);
			if (data[i - (cnt - 1)] == 1) --cur;
		}
	}
	return result;
}

