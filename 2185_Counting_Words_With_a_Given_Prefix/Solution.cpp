#include <Solution.h>
#include <iostream>

int Solution::prefixCount(vector<string> &words, string pref) {
	int result = 0;
	for (const auto &w : words) {
		if (w.size() < pref.size())
			continue;
		int i = 0;
		for (; i < pref.size(); ++i) {
			if (w[i] != pref[i])
				break;
		}
		result += i == pref.size() ? 1 : 0;
	}
	return result;
}
