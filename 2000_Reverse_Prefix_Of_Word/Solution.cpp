#include <Solution.h>
#include <iostream>

using std::swap;
string Solution::reversePrefix(string word, char ch) {
	for (int i = 0 ; i < word.size() ; ++i) {
		if (word[i] != ch) continue;

		int l = 0, r = i;
		while (l < r) {
			swap(word[l], word[r]);
			++l;
			--r;
		}
		break;
	}
	return word;
}
