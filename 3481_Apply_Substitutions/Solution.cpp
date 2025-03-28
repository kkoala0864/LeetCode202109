#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
// 012
// %A%
void replace(string &str, unordered_map<string, string> &replaceMap) {
	int idx = str.find("%");

	while (idx != std::string::npos) {
		int next = str.find("%", idx + 1);
		if (next == std::string::npos)
			return;

		string key = str.substr(idx + 1, next - idx - 1);
		string nextStr = str.substr(0, idx) + replaceMap[key] + str.substr(next + 1);
		str = move(nextStr);
		idx = str.find("%");
	}
}

string Solution::applySubstitutions(vector<vector<string>> &replacements, string text) {

	unordered_map<string, string> replaceMap;

	for (const auto &r : replacements) {
		replaceMap[r[0]] = r[1];
	}
	for (auto &e : replaceMap) {
		replace(e.second, replaceMap);
	}

	replace(text, replaceMap);
	return text;
}
