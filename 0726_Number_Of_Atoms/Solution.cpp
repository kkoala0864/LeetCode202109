#include <Solution.h>
#include <iostream>
#include <stack>
#include <map>

using std::stack;
using std::map;
using std::to_string;
using std::pair;

string Solution::countOfAtoms(string formula) {
	stack<pair<string, int>> st;

	int i = 0;
	while (i < formula.size()) {
		if (isupper(formula[i])) {
			string s(1, formula[i++]);
			while (i < formula.size() && islower(formula[i])) s.push_back(formula[i++]);
			st.emplace(pair<string, int>(s, 1));
		} else if (formula[i] == '(' || formula[i] == ')') {
			st.emplace(pair<string, int>(string(1, formula[i++]), 1));
		} else {
			string ts(1, formula[i++]);
			while (i < formula.size() && isdigit(formula[i])) {
				ts.push_back(formula[i++]);
			}
			int times = stoi(ts);
			if (st.top().first == ")") {
				st.pop();
				stack<pair<string, int>> tmp;
				while (!st.empty() && st.top().first != "(") {
					st.top().second *= times;
					tmp.emplace(st.top());
					st.pop();
				}
				st.pop();
				while (!tmp.empty()) {
					st.emplace(tmp.top());
					tmp.pop();
				}
			} else {
				st.top().second *= times;
			}
		}
	}
	map<string, int> m;
	while (!st.empty()) {
		if (st.top().first != "(" && st.top().first != ")") {
			m[st.top().first] += st.top().second;
		}
		st.pop();
	}
	string result;
	for (const auto& e : m) {
		result += e.first;
		if (e.second > 1) {
			result += to_string(e.second);
		}
	}
	return result;
}
