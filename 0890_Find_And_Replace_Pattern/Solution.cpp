#include <Solution.h>
#include <iostream>

string convert(string &s) {
	vector<char> map(26, ' ');

	string result;
	char mc = 'a' - 1;
	for (const auto &c : s) {
		if (map[c - 'a'] == ' ') {
			map[c - 'a'] = ++mc;
		}
		result.push_back(map[c - 'a']);
	}
	return result;
}

vector<string> Solution::findAndReplacePattern(vector<string> &words, string pattern) {
	int n = pattern.size();
	string golden = convert(pattern);

	vector<string> result;
	for (auto &w : words) {
		if (golden == convert(w))
			result.emplace_back(w);
	}

	return result;
}
