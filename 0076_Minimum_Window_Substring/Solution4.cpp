#include <Solution.h>
#include <iostream>
#include <climits>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

string Solution::minWindow4(string s, string t) {
	unordered_map<char, int> uMap;
	for (const auto &iter : t)
		++uMap[iter];

	string result;
	int cnt = t.size();
	int size = INT_MAX, start = 0;
	while (start < s.size() && uMap.find(s[start]) == uMap.end())
		++start;
	int iter = start;
	while (iter < s.size()) {
		char cur = s[iter];
		if (uMap.find(cur) == uMap.end()) {
			++iter;
			continue;
		}
		--uMap[cur];
		if (uMap[cur] >= 0)
			--cnt;
		while (cnt == 0) {
			if ((iter - start + 1) < size) {
				size = iter - start + 1;
				result = s.substr(start, size);
			}
			char ch = s[start];
			if (uMap.find(ch) != uMap.end()) {
				++uMap[ch];
				if (uMap[ch] > 0)
					++cnt;
			}
			++start;
		}
		while (start < s.size() && uMap.find(s[start]) == uMap.end())
			++start;
		++iter;
	}
	return result;
}
