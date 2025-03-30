#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool check(const string &lhs, const string &rhs) {
	string s = lhs + rhs;

	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r])
			return false;
		++l;
		--r;
	}
	return true;
}

int Solution::longestPalindrome(string s, string t) {
	int result = 0;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i; j < s.size(); ++j) {
			string lhs = s.substr(i, j - i + 1);
			if (check(lhs, ""))
				result = max(result, (int)lhs.size());
			for (int x = 0; x < t.size(); ++x) {
				for (int y = x; y < t.size(); ++y) {
					string rhs = t.substr(x, y - x + 1);
					if (check(rhs, ""))
						result = max(result, (int)rhs.size());
					if (check(lhs, rhs)) {
						result = max(result, (int)(lhs.size() + rhs.size()));
					}
				}
			}
		}
	}

	return result;
}
