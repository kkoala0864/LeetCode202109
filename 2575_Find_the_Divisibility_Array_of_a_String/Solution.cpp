#include <Solution.h>
#include <iostream>

vector<int> Solution::divisibilityArray(string word, int m) {
	vector<int> result(word.size(), 0);

	long long v = 0;
	for (int i = 0 ; i < word.size() ; ++i) {
		v *= 10;
		v += (long long)(word[i] - '0');
		result[i] = (v % m == 0);
		v %= m;
	}

	return result;
}
