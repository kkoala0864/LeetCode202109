#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::pair;
using std::sort;
using std::vector;

string Solution::longestDiverseString(int a, int b, int c) {
	vector<pair<int, char>> list;
	list.emplace_back(pair<int, char>(a, 'a'));
	list.emplace_back(pair<int, char>(b, 'b'));
	list.emplace_back(pair<int, char>(c, 'c'));

	vector<pair<int, char>> ret;
	bool find = false;

	while (true) {
		find = false;
		sort(list.begin(), list.end(), std::greater<pair<int, char>>());
		for (int i = 0; i < 3; ++i) {
			if (list[i].first == 0)
				continue;
			if (ret.empty() || ret.back().second != list[i].second) {
				ret.emplace_back(list[i]);
				ret.back().first = 1;
				find = true;
				--list[i].first;
				break;
			} else {
				if (ret.back().first == 2)
					continue;
				++ret.back().first;
				--list[i].first;
				find = true;
				break;
			}
		}
		if (!find)
			break;
	}
	string result;
	for (const auto &e : ret)
		result += string(e.first, e.second);
	return result;
}
