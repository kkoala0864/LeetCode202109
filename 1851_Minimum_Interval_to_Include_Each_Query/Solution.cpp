#include <Solution.h>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

vector<int> Solution::minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
	map<int, vector<int>> line;

	for (const auto& i : intervals) {
		int len = i[1] - i[0] + 1;
		line[i[0]].emplace_back(len);
		line[i[1] + 1].emplace_back(-len);
	}

	vector<pair<int, int>> ql;
	for (int i = 0 ; i < queries.size() ; ++i) ql.emplace_back(pair<int, int>(queries[i], i));
	sort(ql.begin(), ql.end());

	map<int, int> lenInfo;
	vector<int> result(queries.size(), -1);

	int i = 0;
	auto iter = line.begin();

	while (i < queries.size() && ql[i].first < iter->first) {
		++i;
	}
	if (i == queries.size()) return result;

	for (; i < queries.size() ; ++i) {
		int qv = ql[i].first;
		int qi = ql[i].second;

		while (iter != line.end() && iter->first <= qv) {
			for (const auto& v : iter->second) {
				if (v > 0) {
					++lenInfo[v];
				} else {
					--lenInfo[-v];
					if (lenInfo[-v] == 0) lenInfo.erase(-v);
				}
			}
			++iter;
		}
		if (iter == line.end()) break;
		if (lenInfo.empty()) continue;
		result[qi] = lenInfo.begin()->first;
	}
	return result;
}

