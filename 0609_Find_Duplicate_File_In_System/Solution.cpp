#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<vector<string>> Solution::findDuplicate(vector<string> &paths) {
	unordered_map<string, vector<string>> uMap;

	for (auto &p : paths) {
		vector<string> info;
		string local;
		for (const auto &c : p) {
			if (c != ' ')
				local.push_back(c);
			else {
				if (local.size() > 0) {
					info.emplace_back(local);
					local = "";
				}
			}
		}
		if (local.size() > 0) {
			info.emplace_back(local);
			local = "";
		}

		for (int i = 1; i < info.size(); ++i) {
			int left = info[i].find("(");
			string content = info[i].substr(left + 1, info[i].size() - left - 2);
			info[i].resize(left);
			info[i] = info[0] + "/" + info[i];
			uMap[content].emplace_back(info[i]);
		}
	}

	vector<vector<string>> result;
	for (auto &e : uMap) {
		if (e.second.size() > 1) {
			result.emplace_back(e.second);
		}
	}
	return result;
}
