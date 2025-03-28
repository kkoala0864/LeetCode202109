#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

string Solution::simplifyPath(string path) {
	stack<string> st;
	int idx = 0;
	string result;
	while (idx < path.size() && path[idx] == '/')
		++idx;
	int start = idx;

	while (idx < path.size()) {
		while (idx < path.size() && path[idx] != '/')
			++idx;
		string str = path.substr(start, idx - start);
		if (str == "..") {
			if (!st.empty()) {
				st.pop();
			}
		} else if (str != ".")
			st.emplace(str);
		while (idx < path.size() && path[idx] == '/')
			++idx;
		start = idx;
	}
	while (!st.empty()) {
		result = "/" + st.top() + result;
		st.pop();
	}
	return result.empty() ? "/" : result;
}
