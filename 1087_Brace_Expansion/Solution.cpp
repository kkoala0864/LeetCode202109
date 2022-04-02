#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::sort;

void dfs(vector<vector<string>>& parse, int idx, string local, vector<string>& result) {
	if (idx == parse.size()) {
		result.emplace_back(local);
		return;
	}
	for (auto& it : parse[idx]) dfs(parse, idx + 1, local + it, result);
}

vector<string> Solution::expand(string s) {
	vector<vector<string>> parse;
	string local("");
	for (int i = 0 ; i < s.size() ; ++i) {
		if (s[i] != '{') local.push_back(s[i]);
		else {
			if (!local.empty()) parse.push_back({local});
			local = "";
			vector<string> tmp;
			for (; s[i] != '}' ; ++i) {
				if (s[i] >= 'a' && s[i] <= 'z') {
					tmp.emplace_back(string(1, s[i]));
				}
			}
			sort(tmp.begin(), tmp.end());
			parse.emplace_back(tmp);
		}
	}
	if (!local.empty()) parse.push_back({local});
	vector<string> result;
	dfs(parse, 0, "", result);
	return result;
}
