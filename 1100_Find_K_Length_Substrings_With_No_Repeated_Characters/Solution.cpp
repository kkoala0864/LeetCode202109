#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::numKLenSubstrNoRepeats(string s, int k) {
	if (s.size() < k) return 0;
	vector<int> cnt(26, 1);

	int start = 0, iter = 0;
	int result = 0;
	while (iter < s.size() && start <= (s.size() - k + 1)) {
		int idx = s[iter] - 'a';
		while (cnt[idx] == 0) {
			++cnt[s[start++] -'a'];
			++k;
		}
		--cnt[idx];
		--k;
		if (k < 0) {
			++cnt[s[start++] - 'a'];
			++k;
		}
		if (k == 0) ++result;
		++iter;
	}
	return result;
}
