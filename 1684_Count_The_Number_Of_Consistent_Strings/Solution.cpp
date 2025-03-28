#include <Solution.h>
#include <iostream>

int Solution::countConsistentStrings(string allowed, vector<string> &words) {
	vector<bool> allow(26, false);

	for (const auto &c : allowed) {
		allow[c - 'a'] = true;
	}
	int result = 0;
	for (const auto &w : words) {
		bool check = true;
		for (const auto &c : w) {
			if (!allow[c - 'a']) {
				check = false;
				break;
			}
		}
		if (check)
			++result;
	}
	return result;
}
