#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

vector<string> Solution::stringMatching(vector<string>& words) {
	auto cmp = [](const string& lhs, const string& rhs) {
		return lhs.size() < rhs.size();
	};

	sort(words.begin(), words.end(), cmp);

	vector<string> result;
	for (int i = 0 ; i < words.size() ; ++i) {
		for (int j = i + 1 ; j < words.size() ; ++j) {
			if (words[j].find(words[i]) != string::npos) {
				result.emplace_back(words[i]);
				break;
			}
		}
	}
	return result;
}
