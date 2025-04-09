#include <Solution.h>
#include <iostream>
#include <vector>

int Solution::minChanges(string s) {
	vector<int> list;

	int cnt = 1;
	for (int i = 1 ; i < s.size() ; ++i) {
		if (s[i] != s[i-1]) {
			list.emplace_back(cnt);
			cnt = 1;
		} else {
			++cnt;
		}
	}
	list.emplace_back(cnt);
	int result = 0;
	cnt = 0;
	for (int i = 0 ; i < list.size() ; ++i) {
		list[i] -= cnt;
		cnt = 0;

		if (list[i] & 1) {
			++result;
			++cnt;
		}
	}
	return result;

}
