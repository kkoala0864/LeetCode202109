#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

int Solution::maxProduct(vector<string> &words) {
	vector<unsigned int> distribution;
	for (const auto &word : words) {
		unsigned int encode = 0;
		for (const auto &ch : word) {
			int offset = ch - 'a';
			encode = encode | (1 << offset);
		}
		distribution.emplace_back(encode);
	}

	int result = 0;
	for (int i = 0; i < words.size(); ++i) {
		for (int j = i + 1; j < words.size(); ++j) {
			if (distribution[i] & distribution[j])
				continue;
			result = max(result, (int)(words[i].size() * words[j].size()));
		}
	}
	return result;
}
