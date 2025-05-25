#include <Solution.h>

string Solution::resultingString(string s) {
	stack<int> st;
	for (const auto& c : s) {
		int cur = c - 'a';
		if (st.empty()) {
			st.emplace(cur);
		} else {
			int t = st.top();
			if (t == ((cur + 1) % 26) || t == ((cur + 25) % 26)) {
				st.pop();
			} else {
				st.emplace(cur);
			}
		}
	}
	string result;
	while (!st.empty()) {
		result.push_back(st.top() + 'a');
		st.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}
