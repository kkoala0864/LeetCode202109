#include <Solution.h>

int calculate(int v1, int v2, char oper) {
	if (oper == '+') {
		return v1 + v2;
	} else if (oper == '-') {
		return v1 - v2;
	} else if (oper == '*') {
		return v1 * v2;
	} return 0;
}

void dfs(int start, int end, vector<int>& val, string& oper, vector<vector<vector<int>>>& cache) {
	if (!cache[start][end].empty()) {
		return;
	}

	if (start == end) {
		cache[start][end].emplace_back(val[start]);
		return;
	}
	for (int i = start ; i < end ; ++i) {
		dfs(start, i, val, oper, cache);
		dfs(i + 1, end, val, oper, cache);
		for (const auto& pre : cache[start][i]) {
			for (const auto& post : cache[i + 1][end]) {
				cache[start][end].emplace_back(calculate(pre, post, oper[i]));
			}
		}
	}
}

vector<int> Solution::diffWaysToCompute(string expression) {
	vector<int> val;
	string oper;

	string v;
	for (int i = 0 ; i < expression.size() ; ++i) {
		if (isdigit(expression[i])) {
			v.push_back(expression[i]);
		} else {
			if (!v.empty()) {
				val.emplace_back(stoi(v));
				v.clear();
			}
			oper.push_back(expression[i]);
		}
	}
	if (!v.empty()) val.emplace_back(stoi(v));

	vector<vector<vector<int>>> cache(val.size(), vector<vector<int>>(val.size(), vector<int>()));
	dfs(0, val.size() - 1, val, oper, cache);
	return cache[0][val.size() - 1];
}
