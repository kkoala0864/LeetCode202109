#include <Solution.h>

pair<string, string> parse(const string& s) {
	int f = 0;
	string front, tail;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (s[i] == ' ') break;
		front.push_back(s[i]);
	}
	for (int i = s.size() - 1 ; i >= 0 ; --i) {
		if (s[i] == ' ') break;
		tail.push_back(s[i]);
	}
	reverse(tail.begin(), tail.end());
	return pair<string, string>(front, tail);
}

string merge(const string& lhs, const string& rhs) {
	string result = lhs;
	int idx = rhs.find(" ");
	if (idx == string::npos) return result;
	return result + rhs.substr(idx);
}

vector<string> Solution::beforeAndAfterPuzzles(vector<string>& phrases) {
	unordered_map<string, vector<int>> m;

	vector<pair<string, string>> ft;
	for (int i = 0 ; i < phrases.size() ; ++i) {
		auto p = parse(phrases[i]);
		ft.emplace_back(p);
		m[p.first].emplace_back(i);
	}

	set<string> s;
	for (int i = 0 ; i < phrases.size() ; ++i) {
		for (const auto& ni : m[ft[i].second]) {
			if (i == ni) continue;
			string tmp = merge(phrases[i], phrases[ni]);
			s.emplace(tmp);
		}
	}
	vector<string> result(s.begin(), s.end());
	return result;
}
