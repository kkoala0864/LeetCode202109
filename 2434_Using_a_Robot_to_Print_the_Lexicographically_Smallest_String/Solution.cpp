#include <Solution.h>

string Solution::robotWithString(string s) {
	vector<int> farIdx(26, -1);
	for (int i = 0 ; i < s.size() ; ++i) {
		farIdx[s[i]-'a'] = i;
	}

	int cur = -1;
	for (int i = 0 ; i < 26 ; ++i) {
		int tmp = farIdx[i];
		farIdx[i] = cur;
		cur = max(cur, tmp);
	}
	stack<char> st;
	string result;
	for (int i = 0 ; i < s.size() ; ++i) {
		st.emplace(s[i]);
		while (!st.empty() && farIdx[st.top()-'a'] <= i) {
			result.push_back(st.top());
			st.pop();
		}
	}
	return result;
}
