#include <Solution.h>

string getStr(const vector<string>& s) {
	string result;
	for (int i = 0 ; i < s.size() - 1 ; ++i) {
		result += s[i];
		result += "#";
	}
	result += s.back();
	return result;
}

vector<string> Solution::mostVisitedPattern(vector<string> &username, vector<int> &timestamp, vector<string> &website) {
	vector<pair<int, int>> time;
	int size = username.size();
	for (int i = 0 ; i < size ; ++i) {
		time.emplace_back(pair<int, int>(timestamp[i], i));
	}
	sort(time.begin(), time.end());
	unordered_map<string, vector<string>> patternPerUser;

	for (const auto& t : time) {
		patternPerUser[username[t.second]].emplace_back(website[t.second]);
	}

	unordered_map<string, int> cnt;
	int mxCnt = 0;
	string result;

	for (const auto& e : patternPerUser) {
		unordered_set<string> us;
		vector<vector<string>> cur;
		for (const auto& s : e.second) {
			vector<vector<string>> next = cur;
			vector<string> fh(1, s);
			if (us.count(getStr(fh)) == 0) {
				next.emplace_back(fh);
				us.emplace(getStr(fh));
			}
			for (const auto& c : cur) {
				vector<string> tmp = c;
				tmp.emplace_back(s);
				string h = getStr(tmp);
				if (us.count(h)) continue;
				us.emplace(h);
				if (tmp.size() < 3) next.emplace_back(tmp);
				if (tmp.size() == 3) {
					++cnt[h];
					if (cnt[h] > mxCnt) {
						mxCnt = cnt[h];
						result = h;
					} else if (cnt[h] == mxCnt) {
						result = min(result, h);
					}
				}
			}
			cur = std::move(next);
		}
	}
	vector<string> ret;
	string tmp;
	for (const auto& c : result) {
		if (c != '#') {
			tmp.push_back(c);
		} else {
			ret.emplace_back(tmp);
			tmp = "";
		}
	}
	ret.emplace_back(tmp);
	return ret;
}
