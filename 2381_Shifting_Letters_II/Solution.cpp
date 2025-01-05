#include <Solution.h>
#include <iostream>

using std::vector;

string Solution::shiftingLetters(string s, vector<vector<int>>& shifts) {
	vector<int> m(s.size() + 1, 0);
	for (const auto& s : shifts) {
		m[s[0]] += s[2] == 1 ? 1 : -1;
		m[s[0]] %= 26;
		m[s[1] + 1] += s[2] == 1 ? -1 : 1;
		m[s[1] + 1] %= 26;
	}

	int curOff = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		curOff += (m[i] + 26);
		curOff %= 26;
		s[i] = 'a' + ((s[i] - 'a' + curOff + 26) % 26);
	}
	return s;
}
