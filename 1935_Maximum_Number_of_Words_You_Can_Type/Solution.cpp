#include <Solution.h>

int Solution::canBeTypedWords(string text, string brokenLetters) {
	vector<bool> isBroken(26, false);
	for (const auto& c : brokenLetters) {
		isBroken[c-'a'] = true;
	}

	int result = 0;
	bool bf = false;
	for (const auto& c : text) {
		if (c == ' ') {
			result += (bf == false);
			bf = false;
		} else {
			bf |= isBroken[c-'a'];
		}
	}
	result += (bf == false);
	return result;
}
