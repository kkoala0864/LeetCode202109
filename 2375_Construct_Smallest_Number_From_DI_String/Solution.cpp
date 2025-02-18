#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool dfs(const string& p, vector<bool>& flag, string& result) {
	if (result.size() == p.size() + 1) return true;
	int idx = result.size() - 1;
	int last = result.back() - '0';
	if (p[idx] == 'I') {
		for (int i = last + 1 ; i <= 9 ; ++i) {
			if (flag[i]) continue;
			flag[i] = true;
			result.push_back(i + '0');
			if (dfs(p, flag, result)) return true;
			flag[i] = false;
			result.pop_back();
		}
	} else {
		for (int i = last - 1 ; i >= 1 ; --i) {
			if (flag[i]) continue;
			flag[i] = true;
			result.push_back(i + '0');
			if (dfs(p, flag, result)) return true;
			flag[i] = false;
			result.pop_back();
		}
	}
	return false;
}

string Solution::smallestNumber(string pattern) {
	string result;
	vector<bool> flag(10, false);
	for (int i = 1 ; i <= 9 ; ++i) {
		result.push_back(i + '0');
		flag[i] = true;
		if (dfs(pattern, flag, result)) break;
		flag[i] = false;
		result.pop_back();
	}
	return result;
}
