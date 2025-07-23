#include <Solution.h>

string getAbbr(const string& s, int idx) {
	int fs = s.size() - idx - 2;

	string ret = s.substr(0, idx + 1);
	if (fs > 0) {
		ret += to_string(fs);
	}
	if (idx < s.size() - 1) {
		ret.push_back(s.back());
	}
	return s.size() <= ret.size() ? s : ret;
}

vector<string> Solution::wordsAbbreviation(vector<string> &words) {
	unordered_map<string, vector<string>> groups;

	for (const auto& s : words) {
		string abbr = getAbbr(s, 0);
		groups[abbr].emplace_back(s);
	}

	unordered_map<string, Trie*> roots;
	for (const auto& e : groups) {
		roots[e.first] = new Trie();
		for (const auto& s : e.second) {
			Trie* iter = roots[e.first];
			for (const auto& c : s) {
				if (!iter->ch[c-'a']) iter->ch[c-'a'] = new Trie();
				iter = iter->ch[c-'a'];
				++iter->cnt;
			}
		}
	}

	vector<string> result;
	for (const auto& w : words) {
		string abbr = getAbbr(w, 0);
		Trie* iter = roots[abbr];
		for (int i = 0 ; i < w.size() ; ++i) {
			iter = iter->ch[w[i]-'a'];
			if (iter->cnt == 1) {
				result.emplace_back(getAbbr(w, i));
				break;
			}
		}
	}
	return result;
}
