#include <Solution.h>

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
	c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

vector<string> Solution::spellchecker(vector<string>& wordlist, vector<string>& queries) {
	unordered_set<string> fullSame;
	unordered_map<string, string> cap;
	unordered_map<string, string> vowel;

	for (const auto& w : wordlist) {
		fullSame.emplace(w);
		string cs, vs;
		for (const auto& c : w) {
			cs.push_back(tolower(c));
			vs.push_back(isVowel(c) ? '*' : tolower(c));
		}
		if (cap.count(cs) == 0) cap[cs] = w;
		if (vowel.count(vs) == 0) vowel[vs] = w;
	}
	vector<string> result;
	for (const auto& q : queries) {
		if (fullSame.count(q)) {
			result.emplace_back(q);
			continue;
		}

		string cs, vs;
		for (const auto& c : q) {
			cs.push_back(tolower(c));
			vs.push_back(isVowel(c) ? '*' : tolower(c));
		}

		if (cap.count(cs)) {
			result.emplace_back(cap[cs]);
			continue;
		}
		if (vowel.count(vs)) {
			result.emplace_back(vowel[vs]);
			continue;
		}
		result.emplace_back("");
	}
	return result;
}
