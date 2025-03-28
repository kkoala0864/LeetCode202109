#include <Solution.h>
#include <iostream>

void dfs(const string &num, int idx, long long preValue, long long lastValue, string preStr, const int &target, vector<string> &result) {
	if (idx == num.size()) {
		if (preValue == (long long)target) {
			result.emplace_back(preStr);
		}
		return;
	}

	string str;
	long long v = 0;
	for (int i = idx; i < num.size(); ++i) {
		str.push_back(num[i]);
		v *= 10;
		v += (num[i] - '0');
		if (str.size() > 1 && num[idx] == '0')
			break;

		if (idx == 0) {
			dfs(num, i + 1, v, v, str, target, result);
		} else {
			dfs(num, i + 1, preValue + v, v, preStr + "+" + str, target, result);
			dfs(num, i + 1, preValue - v, -v, preStr + "-" + str, target, result);
			dfs(num, i + 1, preValue - lastValue + lastValue * v, lastValue * v, preStr + "*" + str, target, result);
		}
	}
}

vector<string> Solution::addOperators(string num, int target) {
	vector<string> result;
	dfs(num, 0, 0, 0, "", target, result);
	return result;
}
