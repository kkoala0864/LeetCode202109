#include <Solution.h>
#include <iostream>

using std::pair;
using std::to_string;

vector<string> Solution::generateAbbreviations(string word) {
	vector<pair<string, int>> last, dp;

	last.emplace_back(pair<string, int>("", 0));

	for (int i = 0 ; i < word.size() ; ++i) {
		for (const auto& l : last) {
			dp.emplace_back(l);
			++dp.back().second;

			pair<string, int> tmp;
			tmp.first = l.first;
			if (l.second > 0) {
				tmp.first += to_string(l.second);
			}
			tmp.first.push_back(word[i]);
			tmp.second = 0;
			dp.emplace_back(tmp);
		}
		last = move(dp);
	}
	vector<string> result;
	for (auto& l : last) {
		if (l.second > 0) {
			l.first += to_string(l.second);
		}
		result.emplace_back(l.first);
	}
	return result;
}
