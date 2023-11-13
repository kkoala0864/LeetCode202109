#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool isVowel(char c) {
	char t = tolower(c);
	return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

void getVowelStr(unordered_map<char, int>& m, vector<char>& vt, string& result) {
	for (int i = vt.size() - 1 ; i >= 0 ; --i) {
		if (m.count(vt[i]) > 0) {
			result += string(m[vt[i]], vt[i]);
		}
	}
}

string Solution::sortVowels(string s) {
	vector<char> VT = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
	unordered_map<char, int> m;
	vector<int> vi;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (isVowel(s[i])) {
			++m[s[i]];
			vi.emplace_back(i);
		}
	}

	string vs;
        getVowelStr(m, VT, vs);

	for (int i = 0 ; i < vi.size() ; ++i) {
		s[vi[i]] = vs.back();
		vs.pop_back();
	}
	return s;
}
