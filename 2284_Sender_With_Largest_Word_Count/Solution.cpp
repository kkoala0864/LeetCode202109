#include <Solution.h>
#include <iostream>
#include <unordered_map>

string Solution::largestWordCount(vector<string> &messages, vector<string> &senders) {
	unordered_map<string, int> wordCount;

	int maxCnt = 0;
	string result;
	for (int i = 0; i < messages.size(); ++i) {
		if (messages.empty()) continue;
		int idx = messages[i].find(' ');
		int cnt = 1;
		while (idx != string::npos) {
			++cnt;
			idx = messages[i].find(' ', idx + 1);
		}
		wordCount[senders[i]] += cnt;
		if (maxCnt < wordCount[senders[i]]) {
			maxCnt = wordCount[senders[i]];
			result = senders[i];
		} else if (maxCnt == wordCount[senders[i]]) {
			result = max(senders[i], result);
		}
	}
	return result;
}
