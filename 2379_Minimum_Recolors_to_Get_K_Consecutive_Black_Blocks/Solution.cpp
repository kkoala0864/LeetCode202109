#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minimumRecolors(string blocks, int k) {
	int l = 0;
	int cnt = 0;
	int result = INT_MAX;
	for (int i = 0; i < blocks.size(); ++i) {
		if (blocks[i] == 'W')
			++cnt;

		if (i >= k) {
			if (blocks[i - k] == 'W')
				--cnt;
		}
		if (i >= k - 1) {
			result = min(result, cnt);
		}
	}
	return result;
}
