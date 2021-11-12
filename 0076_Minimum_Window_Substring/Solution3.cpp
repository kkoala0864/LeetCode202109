#include <Solution.h>
#include <iostream>
#include <climits>
#include <unordered_map>

using std::unordered_map;

string Solution::minWindow3(string s, string t) {
	unordered_map<char, int> count;
	for (int i = 0 ; i < t.size() ; ++i) ++count[t[i]];

	int tSize = t.size();
	int size = s.size();
	int minSize = INT_MAX;
	string result("");

	int start = 0;
	while (start < size && count.find(s[start]) == count.end()) ++start;
	int end = start - 1;
	while (end < size) {
		if (tSize > 0) {
			++end;
			if (end < size && count.find(s[end]) != count.end()) {
				--count[s[end]];
				if (count[s[end]] >= 0) --tSize;
			}
		} else {
			if (count.find(s[start]) != count.end()) {
				if ((end - start + 1) < minSize) {
					minSize = end - start + 1;
					result = s.substr(start, minSize);
				}
				++count[s[start]];
				if (count[s[start]] > 0) ++tSize;
			}
			++start;
		}
	}
	return result;
}
