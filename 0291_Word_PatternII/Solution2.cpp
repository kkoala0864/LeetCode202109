#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

bool dfs(const string& p, int pIdx, const string& s, int sIdx, vector<string>& map, unordered_set<string>& uSet) {
	if (pIdx == p.size()) return sIdx == s.size();

	int c = p[pIdx] - 'a';
	if (map[c] != "") {
		string sub = s.substr(sIdx, map[c].size());
		if (map[c] == sub) return dfs(p, pIdx + 1, s, sIdx + map[c].size(), map, uSet);
		else return false;
	} else {
		for (int i = sIdx ; i < s.size() ; ++i) {
			string sub = s.substr(sIdx, i - sIdx + 1);
			if (uSet.find(sub) != uSet.end()) continue;
			map[c] = sub;
			uSet.emplace(sub);
			if (dfs(p, pIdx + 1, s, i + 1, map, uSet)) return true;
			map[c] = "";
			uSet.erase(sub);
		}
	}
	return false;
}

bool Solution::wordPatternMatch2(string pattern, string s) {
	unordered_set<string> uSet;
	vector<string> map(26, "");
	return dfs(pattern, 0, s, 0, map, uSet);
}
