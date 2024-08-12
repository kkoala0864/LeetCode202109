#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

bool dfs(const string& cur, vector<vector<unordered_set<char>>>& um, unordered_set<string>& failed) {
	if (cur.size() == 1) return true;
	if (failed.count(cur)) return false;

	vector<string> list;
	for (int i = 0 ; i < cur.size() - 1 ; ++i) {
		if (um[cur[i]-'A'][cur[i+1]-'A'].empty()) {
			failed.emplace(cur);
			return false;
		}
		string tmp;
		for (const auto& c : um[cur[i]-'A'][cur[i+1]-'A']) {
			tmp.push_back(c);
		}
		list.emplace_back(tmp);
	}

	unordered_set<string> us, next;
	us.emplace("");
	for (const auto& s : list) {
		for (const auto& cur : us) {
			for (const auto& c : s) {
				if (!cur.empty() && um[cur.back()-'A'][c-'A'].empty()) continue;
				string tmp = cur;
				tmp.push_back(c);
				next.emplace(tmp);
			}
		}
		us = move(next);
	}

	for (const auto& c : us) {
		if (dfs(c, um, failed)) return true;
	}
	failed.emplace(cur);
	return false;
}

bool Solution::pyramidTransition(string bottom, vector<string>& allowed) {
	vector<vector<unordered_set<char>>> um(26, vector<unordered_set<char>>(26, unordered_set<char>()));
	unordered_set<string> failed;

	for (const auto& s : allowed) {
		um[s[0]-'A'][s[1]-'A'].emplace(s[2]);
	}

	return dfs(bottom, um, failed);
}
