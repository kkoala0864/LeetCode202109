#include <Solution.h>

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int Solution::maxFreqSum(string s) {
	vector<int> cnt(26, 0);

	int vM = 0, cM = 0;
	for (const auto& c : s) {
		++cnt[c-'a'];
		if (isVowel(c)) {
			vM = max(vM, cnt[c-'a']);
		} else {
			cM = max(cM, cnt[c-'a']);
		}
	}
	return vM + cM;
}
