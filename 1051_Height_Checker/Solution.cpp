#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::heightChecker(vector<int>& heights) {
	vector<int> cnt(101, 0);

	for (int i = 0 ; i < heights.size() ; ++i) {
		++cnt[heights[i]];
	}

	int idx = 0;
	int i = 1;
	for (; i <= 100 ; ++i) if (cnt[i] != 0) break;

	int result = 0;
	while (idx < heights.size() && i <= 100) {
		if (heights[idx++] != i) ++result;
		--cnt[i];
		for (; i <= 100 ; ++i) if (cnt[i] != 0) break;
	}
	return result;

}
