#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::unordered_map;
using std::unordered_set;

// 0 1 2 3 4
void CountScore(const vector<string> &webs, map<string, int> &Scores) {
	unordered_set<string> us;
	for (int i = 0; (i + 2) < webs.size(); ++i) {
		for (int j = i + 1; (j + 1) < webs.size(); ++j) {
			for (int k = j + 1; k < webs.size(); ++k) {
				string tmp = webs[i] + "|" + webs[j] + "|" + webs[k];
				if (us.count(tmp))
					continue;
				us.emplace(tmp);
				++Scores[tmp];
			}
		}
	}
}

// 0 1 2 | 4 5 | 7 8
vector<string> getWeb(const string &webStr) {
	vector<string> ret;
	int idx = webStr.find("|");
	ret.emplace_back(webStr.substr(0, idx));
	int idx2 = webStr.find("|", idx + 1);
	ret.emplace_back(webStr.substr(idx + 1, idx2 - idx - 1));
	ret.emplace_back(webStr.substr(idx2 + 1));
	return ret;
}

vector<string> Solution::mostVisitedPattern(vector<string> &username, vector<int> &timestamp, vector<string> &website) {
	vector<pair<int, int>> tToIdx;
	int size = username.size();
	for (int i = 0; i < size; ++i) {
		tToIdx.emplace_back((pair<int, int>(timestamp[i], i)));
	}

	sort(tToIdx.begin(), tToIdx.end());

	unordered_map<string, vector<string>> userToWeb;
	map<string, int> Scores;

	for (const auto &v : tToIdx) {
		userToWeb[username[v.second]].emplace_back(website[v.second]);
	}

	for (const auto &e : userToWeb) {
		if (e.second.size() < 3)
			continue;
		CountScore(e.second, Scores);
	}
	int MaxScore = 0;
	string maxStr;
	for (const auto &e : Scores) {
		if (MaxScore < e.second) {
			MaxScore = e.second;
			maxStr = e.first;
		} else if (MaxScore == e.second) {
			string s1 = e.first.substr(0, e.first.find("|"));
			string s2 = maxStr.substr(0, maxStr.find("|"));
			if (s1 < s2) {
				maxStr = e.first;
			}
		}
	}

	vector<string> result = getWeb(maxStr);
	return result;
}
