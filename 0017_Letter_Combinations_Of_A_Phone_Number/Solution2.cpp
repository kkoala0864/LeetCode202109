#include <Solution.h>
#include <iostream>

void dfs(const string &digits, int idx, string &local, vector<string> &result, vector<string> &mapping) {
	if (idx == digits.size()) {
		result.emplace_back(local);
		return;
	}

	for (int i = 0; i < mapping[digits[idx] - '0'].size(); ++i) {
		local.push_back(mapping[digits[idx] - '0'][i]);
		dfs(digits, idx + 1, local, result, mapping);
		local.pop_back();
	}
}

vector<string> Solution::letterCombinations2(string digits) {
	if (digits.empty())
		return vector<string>();
	vector<string> mapping(10, "");
	mapping[2] = "abc";
	mapping[3] = "def";
	mapping[4] = "ghi";
	mapping[5] = "jkl";
	mapping[6] = "mno";
	mapping[7] = "pqrs";
	mapping[8] = "tuv";
	mapping[9] = "wxyz";

	vector<string> result;
	string local;
	dfs(digits, 0, local, result, mapping);
	return result;
}
