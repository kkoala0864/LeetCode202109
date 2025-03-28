#include <Solution.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

bool Solution::canChange(string start, string target) {
	vector<pair<char, int>> order;
	int tbCnt = 0;
	for (const auto &v : start) {
		if (v != '_')
			continue;
		++tbCnt;
	}
	int cnt = 0;
	for (int i = 0; i < start.size(); ++i) {
		if (start[i] == '_') {
			++cnt;
		} else {
			if (start[i] == 'L') {
				order.emplace_back(pair<char, int>(start[i], cnt));
			} else {
				order.emplace_back(pair<char, int>(start[i], tbCnt - cnt));
			}
		}
	}

	int si = 0;
	cnt = 0;
	for (int i = 0; i < target.size(); ++i) {
		if (target[i] == '_')
			++cnt;
		else {
			if (si >= order.size() || order[si].first != target[i])
				return false;
			if (target[i] == 'L' && order[si].second < cnt)
				return false;
			else if (target[i] == 'R' && order[si].second < (tbCnt - cnt))
				return false;
			++si;
		}
	}
	return si == order.size();
}
