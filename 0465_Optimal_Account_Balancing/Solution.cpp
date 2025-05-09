#include <Solution.h>

int dfs(int idx, vector<long long>& trans) {
	while (idx < trans.size() && trans[idx] == 0) {
		++idx;
	}
	if (idx == trans.size()) return 0;

	int minTrans = INT_MAX;
	for (int i = idx + 1 ; i < trans.size() ; ++i) {
		if (trans[idx] * trans[i] >= 0) continue;
		trans[i] += trans[idx];
		minTrans = min(minTrans, 1 + dfs(idx + 1, trans));
		trans[i] -= trans[idx];
		if (trans[idx] + trans[i] == 0) break;
	}
	return minTrans;
}

int Solution::minTransfers(vector<vector<int>>& transactions) {
	unordered_map<int, long long> debt;

	for (const auto& t : transactions) {
		debt[t[0]] -= t[2];
		debt[t[1]] += t[2];
	}

	vector<long long> trans;
	for (const auto& e : debt) {
		if (e.second == 0) continue;
		trans.emplace_back(e.second);
	}

	return dfs(0, trans);
}
