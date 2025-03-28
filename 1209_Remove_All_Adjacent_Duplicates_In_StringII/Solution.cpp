#include <Solution.h>
#include <iostream>
#include <vector>

using std::pair;
using std::vector;

string Solution::removeDuplicates(string s, int k) {
	vector<pair<char, int>> st;
	for (const auto &iter : s) {
		if (!st.empty() && st.back().first == iter) {
			++st.back().second;
		} else {
			st.emplace_back(pair<char, int>(iter, 1));
		}
		if (st.back().second == k)
			st.pop_back();
	}
	string result;
	for (const auto &iter : st) {
		result += string(iter.second, iter.first);
	}
	return result;
}
