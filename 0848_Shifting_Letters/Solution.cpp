#include <Solution.h>

string Solution::shiftingLetters(string s, vector<int>& shifts) {

	int sum = 0;
	for (int i = shifts.size() - 1 ; i >= 0 ; --i) {
		sum += shifts[i];
		sum %= 26;
		int v = (s[i] - 'a' + sum) % 26;
		s[i] = v + 'a';
	}
	return s;
}
