#include <Solution.h>
#include <iostream>
#include <climits>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

string Solution::minWindow2(string s, string t) {
	unordered_map<char, int> count;
	int minSize = INT_MAX;
	string result("");
	int size = s.size();
	int cnt = t.size();
	for (const auto &c : t)
		++count[c];

	int start = 0;
	while (start < size && count.find(s[start]) == count.end())
		++start;

	int end = start - 1;
	while (start < size && end < size) {
		if (cnt > 0) {
			++end;
			if (end < size && count.find(s[end]) != count.end()) {
				--count[s[end]];
				if (count[s[end]] >= 0)
					--cnt;
			}
		} else {
			if (count.find(s[start]) != count.end()) {
				if (minSize > (end - start + 1)) {
					minSize = end - start + 1;
					result = s.substr(start, minSize);
				}
				++count[s[start]];
				if (count[s[start]] > 0)
					++cnt;
			}
			++start;
		}
	}
	return result;
}
