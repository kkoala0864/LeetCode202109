#include <Solution.h>
#include <iostream>
#include <climits>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

string Solution::minWindow5(string s, string t) {
	unordered_map<char, int> uMap;

	for (const auto &c : t)
		++uMap[c];

	int l = 0;
	int cnt = t.size();
	int minSize = INT_MAX;
	string result;
	while (l < s.size() && uMap.find(s[l]) == uMap.end())
		++l;
	for (int i = l; i < s.size(); ++i) {
		if (uMap.find(s[i]) == uMap.end())
			continue;

		--uMap[s[i]];
		if (uMap[s[i]] >= 0)
			--cnt;

		while (cnt == 0) {
			if ((i - l + 1) < minSize) {
				minSize = i - l + 1;
				result = s.substr(l, minSize);
			}
			++uMap[s[l]];
			if (uMap[s[l]] > 0)
				++cnt;
			++l;
			while (l < s.size() && uMap.find(s[l]) == uMap.end())
				++l;
		}
	}
	return result;
}
