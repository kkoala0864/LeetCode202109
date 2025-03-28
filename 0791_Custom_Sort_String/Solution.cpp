#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

string Solution::customSortString(string order, string s) {
	vector<int> sIdx(26, -1);
	vector<int> sCnt;

	for (int i = 0; i < order.size(); ++i) {
		sIdx[order[i] - 'a'] = i;
		sCnt.emplace_back(0);
	}

	string result;
	for (const auto &c : s) {
		int idx = sIdx[c - 'a'];
		if (idx == -1)
			result.push_back(c);
		else
			++sCnt[idx];
	}
	for (int i = 0; i < order.size(); ++i) {
		result += string(sCnt[i], order[i]);
	}
	return result;
}
