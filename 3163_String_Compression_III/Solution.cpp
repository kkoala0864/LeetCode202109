#include <Solution.h>
#include <iostream>

using std::to_string;

string Solution::compressedString(string word) {
	string result;

	int i = 0;

	int cnt = 0;
	char c = word[0];
	while (i < word.size()) {
		if (word[i] == c) {
			++cnt;
			if (cnt > 9) {
				result.push_back('9');
				result.push_back(c);
				cnt = 1;
			}
		} else {
			result += to_string(cnt);
			result.push_back(c);
			cnt = 1;
			c = word[i];
		}
		++i;
	}
	result += to_string(cnt);
	result.push_back(c);
	return result;
}
