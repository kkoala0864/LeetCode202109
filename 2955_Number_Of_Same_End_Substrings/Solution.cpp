#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int getV(int v) {
	return (1 + v) * v / 2;
}

vector<int> Solution::sameEndSubstringCount(string s, vector<vector<int>> &queries) {
	vector<vector<int>> prefix;

	vector<int> cnt(26, 0);
	for (int i = 0; i < s.size(); ++i) {
		++cnt[s[i] - 'a'];
		prefix.emplace_back(cnt);
	}
	vector<int> result;
	for (const auto &q : queries) {
		int v = 0;
		for (int i = 0; i < 26; ++i) {
			if (prefix[q[1]][i] == 0)
				continue;
			if (q[0] > 0) {
				v += getV(prefix[q[1]][i] - prefix[q[0] - 1][i]);
			} else {
				v += getV(prefix[q[1]][i]);
			}
		}
		result.emplace_back(v);
	}
	return result;
}
