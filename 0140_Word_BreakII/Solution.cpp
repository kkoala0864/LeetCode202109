#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

void dfs(const string& s, int start, int end, unordered_set<string>& uSet, vector<vector<unordered_set<string>>>& cache, vector<vector<bool>>& check) {
	if (start > end) return;
	if (check[start][end]) return;

	check[start][end] = true;
	string str = s.substr(start, end - start + 1);
	if (uSet.find(str) != uSet.end()) cache[start][end].emplace(str);
	for (int i = start ; i < end ; ++i) {
		dfs(s, start, i, uSet, cache, check);
		dfs(s, i+1, end, uSet, cache, check);
		if (cache[start][i].size() > 0 && cache[i+1][end].size() > 0) {
			for (const auto& f : cache[start][i]) {
				for (const auto& b : cache[i+1][end]) {
					cache[start][end].insert(f + " " + b);
				}
			}
		}
	}
}

vector<string> Solution::wordBreak(string s, vector<string>& wordDict) {
	int n = s.size();
	unordered_set<string> uSet;
	for (const auto& s : wordDict) uSet.emplace(s);

	vector<vector<unordered_set<string>>> cache(n, vector<unordered_set<string>>(n, unordered_set<string>()));
	vector<vector<bool>> check(n, vector<bool>(n, false));

	dfs(s, 0, n-1, uSet, cache, check);
	vector<string> result;
	for (auto& s : cache[0][n-1]) result.emplace_back(s);
	return result;
}
