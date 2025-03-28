#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <queue>

using std::queue;
using std::unordered_set;

int Solution::ladderLength3(string beginWord, string endWord, vector<string> &wordList) {
	unordered_set<string> uSet;
	for (const auto &w : wordList)
		uSet.emplace(w);

	queue<string> que, next;
	int result = 1;

	que.emplace(beginWord);
	while (!que.empty()) {
		string cur = que.front();
		que.pop();

		if (cur == endWord)
			return result;
		string tmp = cur;
		for (int i = 0; i < tmp.size(); ++i) {
			tmp = cur;
			for (char c = 'a'; c <= 'z'; ++c) {
				tmp[i] = c;
				if (tmp == cur)
					continue;
				if (uSet.find(tmp) == uSet.end())
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
	return 0;
}
