#include <Solution.h>
#include <iostream>

bool check(char ch) {
	return ch >= 'A' && ch <= 'Z';
}

bool Solution::detectCapitalUse(string word) {
	if (word.empty())
		return false;

	bool prev = true, cur = true;
	for (int i = 1; i < word.size(); ++i) {
		if (i == 1) {
			prev = check(word[1]);
		} else {
			cur = check(word[i]);
			if (cur != prev)
				return false;
			prev = cur;
		}
	}

	if (word.size() > 1 && !check(word[0]) && check(word[1]))
		return false;

	return true;
}
