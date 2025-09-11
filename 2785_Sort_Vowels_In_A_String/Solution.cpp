#include <Solution.h>

bool isVowels(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string Solution::sortVowels(string s) {
	string vs;
	for (const auto& c : s) {
		if (isVowels(c)) {
			vs.push_back(c);
		}
	}
	sort(vs.begin(), vs.end());
	int vi = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (isVowels(s[i])) {
			s[i] = vs[vi++];
		}
	}
	return s;
}
