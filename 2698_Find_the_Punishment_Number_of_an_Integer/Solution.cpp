#include <Solution.h>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::to_string;

bool check(const string& s, int idx, int target) {
	if (idx == s.size()) return target == 0;

	int cv = 0;
	for (int i = idx ; i < s.size() ; ++i) {
		cv *= 10;
		cv += (s[i] - '0');
		if (cv > target) break;
		if (check(s, i + 1, target - cv)) return true;
	}
	return false;
}

int Solution::punishmentNumber(int n) {
	int result = 0;

	for (int i = 1 ; i <= n ; ++i) {
		int v = i * i;
		string s = to_string(v);
		if (check(s, 0, i)) {
			result += v;
		}
	}
	return result;
}
