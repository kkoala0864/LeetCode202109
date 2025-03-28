#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <climits>

using std::unordered_map;
string Solution::minWindow(string s, string t) {
	string result;
	int count = t.size(), minSize = INT_MAX;
	int size = s.size();
	unordered_map<char, int> record;
	for (const auto &iter : t)
		++record[iter];

	int left = 0;
	while (left < size && record.find(s[left]) == record.end())
		++left;

	int right = left - 1;
	while (left < size && right < size) {
		if (count > 0) {
			++right;
			if (right < size && record.find(s[right]) != record.end()) {
				--record[s[right]];
				if (record[s[right]] >= 0)
					--count;
			}
		} else {
			if ((0 == count) && record.find(s[left]) != record.end()) {
				if ((right - left + 1) < minSize) {
					minSize = right - left + 1;
					result = s.substr(left, minSize);
				}
			}
			if (left < size && record.find(s[left]) != record.end()) {
				++record[s[left]];
				if (record[s[left]] > 0)
					++count;
			}
			++left;
		}
	}
	return result;
}
