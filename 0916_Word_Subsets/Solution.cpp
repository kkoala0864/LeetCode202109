#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

vector<string> Solution::wordSubsets(vector<string> &words1, vector<string> &words2) {
	vector<int> golden(26, 0);

	for (const auto &w : words2) {
		vector<int> local(26, 0);
		for (const auto &c : w)
			++local[c - 'a'];
		for (int i = 0; i < 26; ++i)
			golden[i] = max(golden[i], local[i]);
	}

	vector<string> result;
	for (const auto &w : words1) {
		vector<int> local(26, 0);
		for (const auto &c : w)
			++local[c - 'a'];

		int i = 0;
		for (; i < 26; ++i)
			if (golden[i] > local[i])
				break;
		if (i == 26)
			result.emplace_back(w);
	}
	return result;
}
