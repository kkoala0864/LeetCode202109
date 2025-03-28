#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::calculateTime2(string keyboard, string word) {
	vector<int> idx(26, 0);

	for (int i = 0; i < keyboard.size(); ++i) {
		idx[keyboard[i] - 'a'] = i;
	}

	int cur = 0;
	int result = 0;
	for (const auto &c : word) {
		result += abs(idx[c - 'a'] - cur);
		cur = idx[c - 'a'];
	}
	return result;
}
