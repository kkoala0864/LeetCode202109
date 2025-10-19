#include <Solution.h>

string rotate(const string& s, int b) {
	return s.substr(s.size() - b) + s.substr(0, s.size() - b);
}

string add(const string& s, int a) {
	string result = s;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (i & 1) {
			result[i] = (s[i] - '0' + a) % 10 + '0';
		}
	}
	return result;
}

string Solution::findLexSmallestString(string s, int a, int b) {
	queue<string> que;
	unordered_set<string> visited;
	string result(s.size(), '9');

	que.emplace(s);

	while (!que.empty()) {
		string cur = que.front();
		que.pop();

		result = min(result, cur);

		string r = rotate(cur, b);
		string ad = add(cur, a);

		if (visited.count(r) == 0) {
			visited.emplace(r);
			que.emplace(r);
		}
		if (visited.count(ad) == 0) {
			visited.emplace(ad);
			que.emplace(ad);
		}
	}
	return result;
}
