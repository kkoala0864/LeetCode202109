#include <Solution.h>
#include <iostream>

void dfs(string digits, int idx, const vector<string>& mapping, vector<string>& result, string& local) {
	if (idx == digits.size()) {
		result.emplace_back(local);
		return;
	}

	for (const auto& c : mapping[digits[idx]-'0']) {
		local.push_back(c);
		dfs(digits, idx + 1, mapping, result, local);
		local.pop_back();
	}
}

vector<string> Solution::letterCombinations3(string digits) {
	vector<string> result;
	if (digits.empty()) return result;

	vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	string local("");
	dfs(digits, 0, mapping, result, local);
	return result;
}
