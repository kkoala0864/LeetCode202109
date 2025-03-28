#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <queue>

using std::queue;
using std::unordered_set;

int Solution::minMutation(string start, string end, vector<string> &bank) {
	unordered_set<string> uSet;
	for (const auto &b : bank)
		uSet.emplace(b);

	queue<string> que, next;
	string G = "ACGT";
	int result = 0;

	que.emplace(start);

	while (!que.empty()) {
		string cur = que.front();
		que.pop();

		if (cur == end)
			return result;

		string tmp = cur;
		for (int i = 0; i < 8; ++i) {
			tmp = cur;
			for (int j = 0; j < 4; ++j) {
				tmp[i] = G[j];
				if (tmp == cur || uSet.find(tmp) == uSet.end())
					continue;
				uSet.erase(tmp);
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
