#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

string Solution::makeLargestSpecial(string s) {
	int l = 0;

	vector<string> sub;

	int offset = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		offset += (s[i] == '1' ? 1 : -1);

		if (offset != 0) continue;
		// 0 1 2 3 4
		string ss = s.substr(l + 1, i - l - 1);
		sub.emplace_back("1" + makeLargestSpecial(ss) + "0");
		l = i + 1;
	}

	sort(sub.begin(), sub.end(), greater<>());

	string result;
	for (const auto& v : sub) {
		result += v;
	}
	return result;
}
