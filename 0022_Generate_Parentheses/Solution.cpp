#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::unordered_set;
/*
vector<string> Solution::generateParenthesis(int n) {
	vector<unordered_set<string>> map(n, unordered_set<string>());
	for (int j = 1 ; j <= n ; ++j) {
		if (j == 1) {
			map[0].emplace("()");
		} else{
			for (int i = 1 ; i < j ; ++i) {
				for (const auto& iter : map[j-i-1]) {
					for (const auto& front : map[i-1]) {
						string tmp =  front + iter;
						map[j-1].emplace(tmp);
					}
				}
			}
			for (const auto& iter : map[j-2]) {
				string tmp = "(" + iter + ")";
				map[j-1].emplace(tmp);
			}
		}
	}

	vector<string> result;
	for (const auto& iter : map[n-1]) {
		result.emplace_back(iter);
	}
	return result;
}
*/
void dfs(string s, int left, int right, vector<string>& result) {
	if (left == 0 && right == 0) {
		result.emplace_back(s);
		return;
	}

	if (left > 0) {
		dfs(s+"(", left-1, right, result);
	}

	if (right > left) {
		dfs(s+")", left, right - 1, result);
	}
}

vector<string> Solution::generateParenthesis(int n) {
	vector<string> result;
	dfs("", n, n, result);
	return result;
}
