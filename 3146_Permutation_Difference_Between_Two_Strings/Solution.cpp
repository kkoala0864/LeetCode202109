#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
int Solution::findPermutationDifference(string s, string t) {
	vector<int> i1(26, -1);
	vector<int> i2(26, -1);

	for (int i = 0; i < s.size(); ++i) {
		i1[s[i] - 'a'] = i;
		i2[t[i] - 'a'] = i;
	}
	int result = 0;

	for (int i = 0; i < 26; ++i) {
		if (i1[i] == -1)
			continue;
		result += abs(i1[i] - i2[i]);
	}
	return result;
}
