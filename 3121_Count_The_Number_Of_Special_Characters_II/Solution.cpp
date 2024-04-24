#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
int Solution::numberOfSpecialChars(string word) {
	vector<int> v(26, -1);

	for (int i = 0 ; i < word.size() ; ++i) {
		if (word[i] >= 'a' && word[i] <= 'z') {
			int idx = word[i] - 'a';
			v[idx] = max(v[idx], i);
		}
	}

	int result = 0;
	for (int i = 0 ; i < word.size() ; ++i) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			int idx = word[i] - 'A';
			if (v[idx] == -1) continue;

			if (i > v[idx]) {
				++result;
			}
			v[idx] = -1;
		}
	}
	return result;

}
