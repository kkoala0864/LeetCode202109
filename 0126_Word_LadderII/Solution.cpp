#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using std::unordered_set;
using std::unordered_map;
using std::queue;
using std::pair;

vector<vector<string>> Solution::second(string beginWord, string endWord, vector<string>& wordList) {
	vector<vector<string>> result;
	unordered_map<string, int> cnt;
	for (const auto& word : wordList) cnt[word] = INT_MAX;
	if (cnt.find(endWord) == cnt.end()) return result;
	cnt[beginWord] = 0;

	queue<pair<string, vector<string>>> que;
	que.push({beginWord, {beginWord}});
	while (!que.empty()) {
		auto cur = que.front();
		string curStr = cur.first;
		vector<string> curVec = cur.second;
		que.pop();

		if (curStr == endWord) {
			result.emplace_back(curVec);
			continue;
		}

		string replStr = curStr;
		for (int i = 0 ; i < curStr.size() ; ++i) {
			for (char c = 'a' ; c <= 'z' ; ++c) {
				replStr[i] = c;
				if (replStr == curStr) continue;
				if (cnt.find(replStr) == cnt.end()) continue;
				if (cnt[replStr] < curVec.size()) continue;
				cnt[replStr] = curVec.size();
				curVec.emplace_back(replStr);
				que.push({replStr, curVec});
				curVec.pop_back();
			}
			replStr = curStr;
		}
	}
	return result;
}

vector<vector<string>> Solution::findLadders(string beginWord, string endWord, vector<string>& wordList) {
	vector<vector<string>> result;
	unordered_set<string> uSet;
	bool endExisted = false;
	for (const auto& word : wordList) {
		if (word == endWord) endExisted = true;
		if (word != beginWord) uSet.emplace(word);
	}
	if (!endExisted) return result;

	unordered_map<string, vector<vector<string>>> uMap;
	unordered_map<string, unordered_set<string>> indegree;
	queue<string> que, next;
	vector<string> hit;

	que.emplace(beginWord);
	uMap[beginWord].push_back({beginWord});

	while (!que.empty()) {
		string cur = que.front();
		que.pop();

		string replStr = cur;
		for (int i = 0 ; i < replStr.size() ; ++i) {
			for (char c = 'a' ; c <= 'z' ; ++c) {
				replStr[i] = c;
				if (uSet.find(replStr) == uSet.end()) continue;
				if (indegree[replStr].find(cur) != indegree[replStr].end()) continue;
				next.emplace(replStr);
				hit.emplace_back(replStr);
				indegree[replStr].emplace(cur);
				for (const auto& ele : uMap[cur]) {
					vector<string> tmp = ele;
					tmp.emplace_back(replStr);
					uMap[replStr].emplace_back(tmp);
				}
			}
			replStr = cur;
		}
		if (que.empty()) {
			if (uMap.find(endWord) != uMap.end()) break;
			que = move(next);
			while (!hit.empty()) {
				uSet.erase(hit.back());
				hit.pop_back();
			}
		}
	}
	return uMap[endWord];
}
