#include <Solution.h>

vector<int> Solution::peopleIndexes(vector<vector<string>>& favoriteCompanies) {
	vector<int> result;

	int size = favoriteCompanies.size();
	vector<unordered_set<string>> fset;
	for (const auto& c : favoriteCompanies) {
		unordered_set<string> us;
		for (const auto& s : c) us.emplace(s);
		fset.emplace_back(us);
	}

	for (int i = 0 ; i < size ; ++i) {
		int cnt = 0;
		for (int j = 0 ; j < size ; ++j) {
			if (i == j) continue;
			if (favoriteCompanies[j].size() <= favoriteCompanies[i].size()) continue;
			int idx = 0;
			for (; idx < favoriteCompanies[i].size() ; ++idx) {
				if (fset[j].count(favoriteCompanies[i][idx]) == 0) break;
			}
			if (idx == favoriteCompanies[i].size()) {
				++cnt;
			}
		}
		if (cnt == 0) result.emplace_back(i);
	}

	return result;
}
