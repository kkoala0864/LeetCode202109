#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

void dfs(const string& s, int idx, int cnt, string local, vector<string>& result) {
	if (cnt == 4) {
		if (idx < s.size() - 1 && s[idx] == '0') return;
		string sub = s.substr(idx);
		if (sub.empty() || sub.size() > 3) return;
		if (stoi(sub) > 255) return;
		result.emplace_back(local + "." + sub);
	}

	if (s[idx] == '0') {
		string tmp = "0";
		dfs(s, idx + 1, cnt + 1, cnt == 1 ? "0" : local + "." + tmp, result);
	} else {
		string sub;
		for (int i = idx ; i < min(idx + 3, (int)s.size()) ; ++i) {
			sub.push_back(s[i]);
			if (stoi(sub) > 255) break;
			dfs(s, i + 1, cnt + 1, cnt == 1 ? sub : local + "." + sub, result);
		}
	}
}

vector<string> Solution::restoreIpAddresses2(string s) {
	vector<string> result;
	int cnt = 1;
	dfs(s, 0, cnt, "", result);
	return result;
}
