#include <Solution.h>
#include <iostream>

bool Solution::arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
	int x = 0, y = 0;
	for (int i = 0; i < word1.size(); ++i) {
		for (const auto &c : word1[i]) {
			if (x >= word2.size())
				return false;
			if (c != word2[x][y++]) {
				return false;
			}
			if (y >= word2[x].size()) {
				++x;
				y = 0;
			}
		}
	}
	return x == word2.size() && y == 0;
}
