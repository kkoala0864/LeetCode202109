#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;
using std::vector;

bool DFS(vector<string> &sMap, unordered_set<string> &uSet, string &pattern, int pIdx, string &s, int sIdx) {
	if (pIdx == pattern.size()) {
		return sIdx == s.size();
	}

	if (sMap[pattern[pIdx] - 'a'] != "") {
		string str = sMap[pattern[pIdx] - 'a'];
		if (str.size() > (s.size() - sIdx))
			return false;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] != s[sIdx + i])
				return false;
		}
		return DFS(sMap, uSet, pattern, pIdx + 1, s, sIdx + str.size());
	}

	for (int size = 1; (sIdx + size) <= s.size(); ++size) {
		string str = s.substr(sIdx, size);
		if (uSet.count(str) > 0)
			continue;
		uSet.emplace(str);
		sMap[pattern[pIdx] - 'a'] = s.substr(sIdx, size);
		if (DFS(sMap, uSet, pattern, pIdx + 1, s, sIdx + size))
			return true;
		sMap[pattern[pIdx] - 'a'] = "";
		uSet.erase(str);
	}
	return false;
}

bool Solution::wordPatternMatch(string pattern, string s) {
	vector<string> sMap(26, "");
	unordered_set<string> uSet;
	return DFS(sMap, uSet, pattern, 0, s, 0);
}
