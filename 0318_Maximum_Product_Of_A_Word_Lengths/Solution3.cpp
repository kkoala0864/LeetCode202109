#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxProduct3(vector<string>& words) {
	vector<int> bitVec;
	int result = 0;

	for (const auto& word : words) {
		int bit = 0;
		for (const auto& c : word) bit |= 1 << (c - 'a');
		for (int i = 0 ; i < bitVec.size() ; ++i) {
			if (!(bit & bitVec[i])) result = max(result, (int)(word.size() * words[i].size()));
		}
		bitVec.emplace_back(bit);
	}
	return result;
}

