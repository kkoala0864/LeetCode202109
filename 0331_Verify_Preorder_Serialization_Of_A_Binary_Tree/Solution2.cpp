#include <Solution.h>
#include <iostream>

bool dfs(const string& s, int& idx) {
	if (idx >= s.size()) return false;

	int start = idx;
	while (idx < s.size() && s[idx] != ',') {
		++idx;
	}
	string val = s.substr(start, idx - start);
	++idx;
	if (val == "#") return true;
	else {
		return dfs(s, idx) && dfs(s, idx);
	}
}

bool Solution::isValidSerialization2(string preorder) {
	int idx = 0;
	return dfs(preorder, idx) && (idx == (preorder.size() + 1));
}
