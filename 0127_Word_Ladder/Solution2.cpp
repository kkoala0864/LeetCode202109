#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <queue>

using std::unordered_set;
using std::queue;

int Solution::ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> uSet;
	queue<string> que, next;

	bool findEndWord = false;
	for (const auto& word : wordList) {
		if (word == endWord) findEndWord = true;
		if (word != beginWord) uSet.emplace(word);
	}
	if (!findEndWord) return 0;
	que.emplace(beginWord);
	int result = 1;
	while (!que.empty()) {
		string cur = que.front();
		que.pop();

		string tmp = cur;
		for (int i = 0 ; i < cur.size() ; ++i) {
			for (char c = 'a' ; c <= 'z' ; ++c) {
				tmp[i] = c;
				if (tmp == endWord) return result + 1;
				if (uSet.find(tmp) == uSet.end()) continue;
				uSet.erase(tmp);
				next.emplace(tmp);
			}
			tmp = cur;
		}
		if (que.empty()) {
			que = move(next);
			++result;
		}
	}
	return 0;
}
