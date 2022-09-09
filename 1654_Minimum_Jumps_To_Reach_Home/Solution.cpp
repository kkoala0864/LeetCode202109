#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <queue>

using std::unordered_set;
using std::pair;
using std::queue;

int Solution::minimumJumps(vector<int>& forbidden, int a, int b, int x) {
	unordered_set<int> uSet;
	for (const auto& f : forbidden) uSet.emplace(f);

	queue<pair<int, int>> que, nq;
	int result = 0;
	que.emplace(pair<int, int>(0, 0));
	uSet.emplace(0);
	while (!que.empty()) {
		int curStep = que.front().first;
		int isBack = que.front().second;
		que.pop();

		if (curStep == x) return result;

		if (isBack == 0) {
			int next = curStep - b;
			if (next >= 0 && uSet.find(next) == uSet.end()) {
				nq.emplace(pair<int, int>(next, 1));
				uSet.emplace(next);
			}
		}

		int next = curStep + a;
		if (next <= (2000 + a + b) && uSet.find(next) == uSet.end()) {
			nq.emplace(pair<int, int>(next, 0));
			uSet.emplace(next);
		}
		if (que.empty()) {
			++result;
			que = move(nq);
		}
	}
	return -1;
}
