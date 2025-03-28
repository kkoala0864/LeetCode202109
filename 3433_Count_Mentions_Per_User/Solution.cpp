#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;

void parseId(const string &s, vector<int> &result) {
	int v = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') {
			++result[v];
			v = 0;
		} else if (s[i] >= '0' && s[i] <= '9') {
			v *= 10;
			v += (s[i] - '0');
		}
	}
	++result[v];
}

vector<int> Solution::countMentions(int numberOfUsers, vector<vector<string>> &events) {
	auto cmp = [](const vector<string> &lhs, const vector<string> &rhs) {
		int lv = stoi(lhs[1]);
		int rv = stoi(rhs[1]);
		return lv == rv ? lhs[0] == "OFFLINE" ? true : false : lv < rv;
	};
	sort(events.begin(), events.end(), cmp);

	vector<int> result(numberOfUsers, 0);
	int allCnt = 0;
	vector<int> lastOffline(numberOfUsers, -1);

	for (const auto &e : events) {
		int t = stoi(e[1]);
		if (e[0] == "MESSAGE") {
			if (e[2] == "ALL")
				++allCnt;
			else if (e[2] == "HERE") {
				for (int i = 0; i < numberOfUsers; ++i) {
					if (t > lastOffline[i])
						++result[i];
				}
			} else {
				parseId(e[2], result);
			}
		} else {
			int id = stoi(e[2]);
			lastOffline[id] = t + 59;
		}
	}
	for (int i = 0; i < numberOfUsers; ++i)
		result[i] += allCnt;
	return result;
}
