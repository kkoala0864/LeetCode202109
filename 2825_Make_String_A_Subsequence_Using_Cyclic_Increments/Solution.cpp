#include <Solution.h>
#include <iostream>

bool Solution::canMakeSubsequence(string str1, string str2) {
	int i2 = 0;

	for (int i = 0; i < str1.size() && i2 < str2.size(); ++i) {
		char nextChar = ((str1[i] - 'a' + 1) % 26) + 'a';
		if (str1[i] == str2[i2] || nextChar == str2[i2])
			++i2;
	}
	return i2 == str2.size();
}
