#include <Solution.h>

string Solution::smallestSubsequence(string s) {
	string str;
	vector<int> cnt(26, 0);
	for (const auto& c : s) ++cnt[c-'a'];
	vector<bool> visited(26, false);

	for (const auto& c : s) {
		if (!visited[c-'a']) {
			while (str.size() > 0 && str.back() > c && cnt[str.back()-'a'] > 0) {
				visited[str.back()-'a'] = false;
				str.pop_back();
			}
			str.push_back(c);
			visited[c-'a'] = true;
		}
		--cnt[c-'a'];
		cout << str << endl;
	}
	return str;

}
