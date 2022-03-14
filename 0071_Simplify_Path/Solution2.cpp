#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

string Solution::simplifyPath2(string path) {
	stack<string> st;
	string s;
	path.push_back('/');
	for (int i = 0 ; i < path.size() ; ++i) {
		if (path[i] == '/') {
			if (!s.empty()) {
				if (s == "..") {
					if (!st.empty()) st.pop();
				} else if (s != ".") {
					st.emplace(s);
				}
			}
			s.clear();
		} else {
			s.push_back(path[i]);
		}
	}
	string result;
	while (!st.empty()) {
		result = "/" + st.top() + result;
		st.pop();
	}
	return result.empty() ? "/" : result;
}
