#include <Solution.h>

void appendUS(unordered_set<string>& us, unordered_set<string>& sub) {
	if (us.empty()) {
		us = move(sub);
	} else {
		unordered_set<string> next;
		for (const auto& s : us) {
			for (const auto& ss : sub) {
				next.emplace(s + ss);
			}
		}
		us = move(next);
	}
}

void appendChar(unordered_set<string>& us, char& c) {
	if (us.empty()) {
		us.emplace(string(1,c));
	} else {
		unordered_set<string> next;
		for (const auto& s : us) {
			next.emplace(s + string(1,c));
		}
		us = move(next);
	}
}

unordered_set<string> dfs(int& idx, string& exp) {
	unordered_set<string> us;
	unordered_set<string> concate;

	for (; idx < exp.size() ; ++idx) {
		if (isalpha(exp[idx])) {
			appendChar(concate, exp[idx]);
		} else {
			if (exp[idx] == '{') {
				auto sub = dfs(++idx, exp);
				appendUS(concate, sub);
			} else if (exp[idx] == ',') {
				for (const auto& v : concate) us.emplace(v);
				concate.clear();
			} else if (exp[idx] == '}') {
				break;
			}
		}
	}
	for (const auto& v : concate) us.emplace(v);
	return us;
}

vector<string> Solution::braceExpansionII(string expression) {
	int idx = 0;
	auto us = dfs(idx, expression);
	vector<string> result(us.begin(), us.end());
	sort(result.begin(), result.end());
	return result;
}
