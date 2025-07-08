#include <Solution.h>

vector<int> Solution::peopleIndexes(vector<vector<string>>& favoriteCompanies) {
	vector<int> result;
	unordered_map<string, unordered_set<int>> strToIdx;

	int size = favoriteCompanies.size();
	vector<pair<vector<string>, int>> clist;

	for (int i = 0 ; i < size ; ++i) {
		clist.emplace_back(pair<vector<string>, int>(favoriteCompanies[i], i));
	}
	auto cmp = [](const pair<vector<string>, int>& lhs, const pair<vector<string>, int>& rhs) {
		return lhs.first.size() > rhs.first.size();
	};

	sort(clist.begin(), clist.end(), cmp);
	for (const auto& c : clist) {
		unordered_set<int> cur = strToIdx[c.first[0]];
		for (int i = 1 ; i < c.first.size() ; ++i) {
			unordered_set<int> next;
			for (const auto& idx : cur) {
				if (strToIdx[c.first[i]].count(idx) == 0) continue;
				next.emplace(idx);
			}
			cur = std::move(next);
			if (cur.empty()) break;
		}
		if (cur.empty()) {
			result.emplace_back(c.second);
			for (const auto& s : c.first) {
				strToIdx[s].emplace(c.second);
			}
		}
	}
	sort(result.begin(), result.end());

	return result;
}
