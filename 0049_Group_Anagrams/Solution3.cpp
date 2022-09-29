#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

string sortStr3(const string& s) {
	vector<int> cnt(26, 0);
	for (const auto& c : s) ++cnt[c-'a'];

	string result;
	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt[i] > 0) result += string(cnt[i], i + 'a');
	}
	return result;
}

vector<vector<string>> Solution::groupAnagrams3(vector<string>& strs) {
	unordered_map<string, vector<string>> anagramList;
	for (auto& s : strs) {
		string ss = sortStr3(s);
		anagramList[ss].emplace_back(s);
	}
	vector<vector<string>> result;
	for (auto& e : anagramList) {
		result.emplace_back(e.second);
	}
	return result;
}
