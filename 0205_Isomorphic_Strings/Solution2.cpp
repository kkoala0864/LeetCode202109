#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::isIsomorphic2(string s, string t) {
	if (s.size() != t.size()) return false;
	unordered_map<int, int> sTot, tTos;

	for (int i = 0 ; i < s.size() ; ++i) {
		if (sTot.count(s[i]) != tTos.count(t[i])) return false;
		if (sTot.count(s[i])) {
			if (sTot[s[i]] != t[i] || tTos[t[i]] != s[i]) return false;
		} else {
			sTot[s[i]] = t[i];
			tTos[t[i]] = s[i];
		}
	}
	return true;
}
