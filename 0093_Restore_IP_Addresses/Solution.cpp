#include <Solution.h>
#include <iostream>

void dfs(const string& s, int idx, vector<string>& result, vector<string>& local) {
	if (idx > s.size()) return;
	if (idx == s.size()) {
		if (local.size() == 4) {
			string insert(local[0]);
			for (int i = 1 ; i < 4 ; ++i) {
				insert.append(".");
				insert.append(local[i]);
			}
			result.emplace_back(insert);
		}
		return;
	}

	int boundary = s[idx] == '0' ? 1 : 3;
	for (int i = 1 ; i <= boundary && (idx + i) <= s.size() ; ++i) {
		string val = s.substr(idx, i);
		if (stoi(val) > 255) continue;
		local.emplace_back(val);
		dfs(s, idx + i, result, local);
		local.pop_back();
	}
}

vector<string> Solution::restoreIpAddresses(string s) {
	vector<string> result;
	if ((s.size() < 4) || (s.size() > 12)) return result;
	vector<string> local;
	dfs(s, 0, result, local);
	return result;
}
