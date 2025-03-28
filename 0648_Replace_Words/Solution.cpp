#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;

string Solution::replaceWords(vector<string> &dictionary, string sentence) {
	unordered_set<string> m;

	for (const auto &d : dictionary) {
		m.emplace(d);
	}

	string result;
	string cur;
	for (int i = 0; i < sentence.size(); ++i) {
		result.push_back(sentence[i]);
		if (sentence[i] == ' ')
			cur = "";
		else
			cur.push_back(sentence[i]);
		if (m.count(cur) == 0)
			continue;
		while ((i + 1) < sentence.size() && sentence[i + 1] != ' ') {
			++i;
		}
		cur = "";
	}
	return result;
}
