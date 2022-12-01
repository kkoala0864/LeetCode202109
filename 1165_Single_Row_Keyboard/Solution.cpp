#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int Solution::calculateTime(string keyboard, string word) {
	vector<int> idx(26, 0);
	for (int i = 0 ; i < keyboard.size() ; ++i) {
		idx[keyboard[i] - 'a'] = i;
	}

	int result = 0;
	int lastIdx = 0;
	for (const auto& c : word) {
		result += abs(idx[c-'a'] - lastIdx);
		lastIdx = idx[c-'a'];
	}
	return result;
}
