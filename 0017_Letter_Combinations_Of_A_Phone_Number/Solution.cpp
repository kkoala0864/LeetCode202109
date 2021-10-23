#include <Solution.h>
#include <iostream>

void dfs(vector<vector<char>>& map, string& digits, int idx, vector<string>& result, string& local) {
	if (idx == digits.size()) {
		result.emplace_back(local);
		return;
	}

	for (int i = 0 ; i < map[digits[idx]-'0'].size() ; ++i) {
		local.push_back(map[digits[idx]-'0'][i]);
		dfs(map, digits, idx+1, result, local);
		local.pop_back();
	}
}

vector<string> Solution::letterCombinations(string digits) {
	vector<vector<char>> map(10);

	map[2] = {'a', 'b', 'c'};
	map[3] = {'d', 'e', 'f'};
	map[4] = {'g', 'h', 'i'};
	map[5] = {'j', 'k', 'l'};
	map[6] = {'m', 'n', 'o'};
	map[7] = {'p', 'q', 'r', 's'};
	map[8] = {'t', 'u', 'v'};
	map[9] = {'w', 'x', 'y', 'z'};

	vector<string> result;
	if (digits.empty()) return result;
	string local("");
	dfs(map, digits, 0, result, local);
	return result;
}
