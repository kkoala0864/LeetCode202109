#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

bool Solution::hasAllCodes(string s, int k) {
	unordered_set<int> uSet;
	int val = 0;
	int mask = (1 << k) - 1;
	int total = pow(2, k);
	for (int i = 0; i < s.size(); ++i) {
		val = (val << 1) | s[i] - '0';
		if (i >= k - 1) {
			val *= mask;
			uSet.emplace(val);
			if (uSet.size() == total)
				return true;
		}
	}
	return false;
}
