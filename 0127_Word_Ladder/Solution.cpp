#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <queue>

using std::unordered_set;
using std::queue;

int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	bool endInList = false;
	for (const auto& iter : wordList) if (iter == endWord) endInList = true;
	if (!endInList) return false;

	unordered_set<string> set;
	for (const auto& iter : wordList) set.emplace(iter);

	queue<string> que, next;
	que.emplace(beginWord);

	int result = 1;
	while (!que.empty()) {
		string cur = que.front();
		que.pop();

		for (int i = 0 ; i < cur.size() ; ++i) {
			string tmp = cur;
			for (char c = 'a' ; c <= 'z' ; ++c) {
				tmp[i] = c;
				if (tmp == cur) continue;
				if (tmp == endWord) return result + 1;
				if (set.find(tmp) != set.end()) {
					next.emplace(tmp);
					set.erase(tmp);
				}
			}
		}

		if (que.empty()) {
			que = move(next);
			++result;
		}
	}
	return 0;
}
