#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using std::max;
using std::priority_queue;
using std::vector;

string Solution::answerString(string word, int numFriends) {
	if (numFriends == 1)
		return word;
	vector<vector<int>> idx(26, vector<int>());
	int size = word.size();

	int maxIdx = -1;
	for (int i = 0; i < size; ++i) {
		idx[word[i] - 'a'].emplace_back(i);
		maxIdx = max(maxIdx, word[i] - 'a');
	}

	priority_queue<string> pq;
	for (const auto &i : idx[maxIdx]) {
		string w;
		if (i >= numFriends - 1) {
			w = word.substr(i);
		} else {
			int sz = size - (numFriends - i - 1) - i;
			w = word.substr(i, sz);
		}
		pq.push(w);
	}
	return pq.top();
}
