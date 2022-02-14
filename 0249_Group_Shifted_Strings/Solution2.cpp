#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<vector<string>> Solution::groupStrings2(vector<string>& strings) {
	auto fn = [] (string s) {
		int diff = s[0] - 'a';
		for (int i = 0 ; i < s.size() ; ++i) {
			if (s[i] - diff < 'a') s[i] = s[i] - diff + 26;
			else s[i] -= diff;
		}
		return s;
	};
	unordered_map<string, vector<string>> map;
	for (auto& s : strings) {
		map[fn(s)].emplace_back(s);
	}

	vector<vector<string>> result;
	for (const auto& iter : map) {
		result.emplace_back(iter.second);
	}
	return result;
}
/*
vector<vector<string>> Solution::groupStrings2(vector<string>& strings) {
	unordered_map<string, int> map;
	for (const auto& s : strings) ++map[s];

	vector<vector<string>> result;

	for (const auto& s : strings) {
		if (map.find(s) != map.end()) {
			vector<string> tmp;

			for (int i = 0 ; i < 26 ; ++i) {
				string tmps = s;
				for (int j = 0 ; j < s.size() ; ++j) {
					tmps[j] = ((tmps[j] - 'a' + i) % 26) + 'a';
				}
				if (map.find(tmps) != map.end()) {
					for (int cnt = 0 ; cnt < map[tmps] ; ++cnt) {
						tmp.emplace_back(tmps);
					}
					map.erase(tmps);
				}
			}
			result.emplace_back(tmp);
		}
	}
	return result;
}*/
