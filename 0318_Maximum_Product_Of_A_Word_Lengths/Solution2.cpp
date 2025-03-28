#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxProduct2(vector<string> &words) {
	vector<int> bitV;
	int result = 0;
	for (int i = 0; i < words.size(); ++i) {
		int bitMask = 0;
		for (const auto &c : words[i])
			bitMask |= (1 << (c - 'a'));
		for (int j = 0; j < bitV.size(); ++j) {
			if (!(bitMask & bitV[j])) {
				result = max(result, (int)words[i].size() * (int)words[j].size());
			}
		}
		bitV.emplace_back(bitMask);
	}
	return result;
}
