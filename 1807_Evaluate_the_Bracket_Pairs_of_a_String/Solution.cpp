#include <Solution.h>
#include <iostream>
#include <stack>
#include <unordered_map>

string dfs(const string& s, int& idx, unordered_map<string, string>& m) {
	if (idx == s.size()) return "";

	string result;
	while (idx < s.size()) {
		if (s[idx] == ')') {
			if (m.count(result) == 0) return "?";
			else return m[result];
		}
		if (s[idx] == '(') {
			++idx;
			string re = dfs(s, idx, m);
			result += re;
		} else {
			result.push_back(s[idx]);
		}
		++idx;
	}
	return result;
}

string Solution::evaluate(string s, vector<vector<string>>& knowledge) {
	unordered_map<string, string> m;
	for (const auto& v : knowledge) {
		m[v[0]] = v[1];
	}

	int idx = 0;
	string result;
	return dfs(s, idx, m);
}
