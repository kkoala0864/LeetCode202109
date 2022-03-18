#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

string Solution::removeDuplicateLetters(string s) {
	vector<char> st;
	vector<int> lastIdx(26, -1);
	vector<bool> flag(26, false);
	for (int i = 0 ; i < s.size() ; ++i) lastIdx[s[i]-'a'] = i;

	for (int i = 0 ; i < s.size() ; ++i) {
		if (flag[s[i]-'a']) continue;
		while (!st.empty() && st.back() > s[i] && i < lastIdx[st.back()-'a']) {
			flag[st.back()-'a'] = false;
			st.pop_back();
		}
		st.emplace_back(s[i]);
		flag[s[i]-'a'] = true;
	}
	string result;
	for (const auto& iter : st) result.push_back(iter);
	return result;
}
