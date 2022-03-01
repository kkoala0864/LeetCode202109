#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::isIsomorphic2(string s, string t) {
	if (s.size() != t.size()) return false;
	unordered_map<char, int> sMap, tMap;

	int id = 1;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (sMap[s[i]] != tMap[t[i]]) return false;
		if (sMap[s[i]] == 0) {
			sMap[s[i]] = id;
			tMap[t[i]] = id;
			++id;
		}
	}
	return true;
}
