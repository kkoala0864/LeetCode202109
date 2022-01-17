#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool Solution::wordPattern2(string pattern, string s) {
	int pIdx = 0;
	int sIdx = 0;

	vector<string> map(26, "");
	unordered_map<string, char> sMap;
	while (sIdx < s.size() && pIdx < pattern.size()) {
		string str("");
		while (sIdx < s.size() && s[sIdx] == ' ') ++sIdx;
		while (sIdx < s.size() && s[sIdx] != ' ') {
			str.push_back(s[sIdx]);
			++sIdx;
		}
		if (map[pattern[pIdx] - 'a'] == "" && sMap.find(str) == sMap.end()) {
			map[pattern[pIdx] - 'a'] = str;
			sMap[str] = pattern[pIdx];
		} else {
			if (str != map[pattern[pIdx] - 'a'] || sMap[str] != pattern[pIdx]) return false;
		}
		++pIdx;
	}
	if (sIdx != s.size() || pIdx != pattern.size()) return false;
	return true;
}
