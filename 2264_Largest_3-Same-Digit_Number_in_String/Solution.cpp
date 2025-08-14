#include <Solution.h>

string Solution::largestGoodInteger(string num) {

	int result = -1;
	vector<int> cnt(10, 0);
	int vCnt = 0;
	int l = 0;

	for (int r = 0 ; r < num.size() ; ++r) {
		int rv = num[r] - '0';
		++cnt[rv];
		if (cnt[rv] == 1) ++vCnt;
		if (r >= 3) {
			int lv = num[l++] - '0';
			--cnt[lv];
			if (cnt[lv] == 0) --vCnt;
		}
		if (r >= 2 && vCnt == 1) result = max(result, rv);
	}
	return result == -1 ? "" : string(3, '0' + result);
}
