#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <climits>

using std::unordered_set;
using std::vector;
using std::max;

bool check(const vector<int>& cnt, int mv) {
	int c = mv;
	for (int i = 0 ; i < 10 ; ++i) {
		if (cnt[i] == 0) continue;
		if (c != cnt[i]) return false;
	}
	return true;
}

int Solution::equalDigitFrequency(string s) {
	unordered_set<string> us;

	int l = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		vector<int> cnt(10, 0);
		int mv = INT_MIN;
		for (int j = i ; j < s.size() ; ++j) {
			++cnt[s[j]-'0'];
			mv = max(mv, cnt[s[j]-'0']);
			if (cnt[s[j] - '0'] == mv && check(cnt, mv)) {
				us.emplace(s.substr(i, j - i + 1));
			}
		}
	}
	return us.size();
}

