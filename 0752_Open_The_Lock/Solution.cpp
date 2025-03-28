#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_set>

using std::queue;
using std::unordered_set;

int Solution::openLock(vector<string> &deadends, string target) {
	queue<string> que, next;
	unordered_set<string> uSet;
	int result = 0;

	for (const auto &d : deadends)
		uSet.emplace(d);

	if (uSet.find("0000") != uSet.end())
		return -1;
	que.emplace("0000");

	while (!que.empty()) {
		string cur = que.front();
		que.pop();

		if (cur == target)
			return result;
		string tmp = cur;
		for (int i = 0; i < 4; ++i) {
			tmp = cur;
			tmp[i] = (cur[i] - '0' + 1) % 10 + '0';
			if (uSet.find(tmp) == uSet.end()) {
				uSet.emplace(tmp);
				next.emplace(tmp);
			}

			tmp[i] = (cur[i] - '0' + 9) % 10 + '0';
			if (uSet.find(tmp) == uSet.end()) {
				uSet.emplace(tmp);
				next.emplace(tmp);
			}
		}

		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return -1;
}
