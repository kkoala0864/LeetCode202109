#include <Solution.h>
#include <iostream>

using std::swap;
using std::cout;
using std::endl;

void reverse2(vector<int>& result, int l, int r) {
	while (l < r) {
		swap(result[l++], result[r--]);
	}
}

vector<int> Solution::findPermutation2(string s) {
	vector<int> result;
	int lastI = 0;
	result.emplace_back(1);
	for (int i = 1 ; i <= s.size() ; ++i) {
		result.emplace_back(i+1);
		if (s[i-1] == 'I') {
			reverse2(result, lastI, i-1);
			lastI = i;
		}

	}
	if (lastI != s.size()) reverse2(result, lastI, s.size());
	return result;
}
