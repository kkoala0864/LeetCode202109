#include <Solution.h>

string Solution::makeFancyString(string s) {
	string result;
	int cnt = 0;
	for (const auto& c : s) {
		if (result.empty() || result.back() != c) {
			result.push_back(c);
			cnt = 1;
		} else {
			if (cnt < 2) {
				result.push_back(c);
				++cnt;
			} else {
				continue;
			}
		}
	}
	return result;
}
