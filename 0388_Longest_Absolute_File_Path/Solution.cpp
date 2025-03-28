#include <Solution.h>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using std::max;
using std::pair;
using std::stack;
using std::vector;

int Solution::lengthLongestPath(string input) {
	vector<string> lines;
	string line;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == '\n') {
			lines.emplace_back(line);
			line.clear();
		} else {
			line.push_back(input[i]);
		}
	}
	lines.emplace_back(line);

	stack<pair<string, int>> st;
	int result = 0;
	int cur = 0;
	for (const auto &l : lines) {
		int tabCnt = 0;
		int i = 0;
		while (i < l.size() && l[i] == '\t') {
			++i;
			++tabCnt;
		}
		while (!st.empty() && tabCnt <= st.top().second) {
			cur -= (st.top().first.size() + 1);
			st.pop();
			if (st.empty())
				cur += 1;
		}
		string sub = l.substr(i);
		cur += (sub.size() + (st.empty() ? 0 : 1));
		st.emplace(pair<string, int>(sub, tabCnt));
		if (sub.find(".") != std::string::npos)
			result = max(cur, result);
	}
	return result;
}
