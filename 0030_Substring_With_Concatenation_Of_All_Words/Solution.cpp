#include <Solution.h>
#include <iostream>
#include <unordered_map>
using std::unordered_map;

void sliding_window(int left, string& s, const int wSize, const int wsSize,
		const int sn, vector<int>& result, unordered_map<string, int>& wCnt) {
	int wordUsed = wsSize;
	bool excessWord = false;
	unordered_map<string, int> cnt;

	for (int right = left ; right <= (sn - wSize)  ; right += wSize) {
		string str = s.substr(right, wSize);
		if (wCnt.find(str) == wCnt.end()) {
			cnt.clear();
			wordUsed = wsSize;
			excessWord = false;
			left = right + wSize;
		} else {
			while (right - left == (wSize * wsSize) || excessWord) {
				string lMostStr = s.substr(left, wSize);
				left += wSize;
				--cnt[lMostStr];
				if (cnt[lMostStr] == wCnt[lMostStr]) excessWord = false;
				else ++wordUsed;
			}
			++cnt[str];
			if (cnt[str] <= wCnt[str]) --wordUsed;
			else excessWord = true;
			if (wordUsed == 0 && !excessWord) result.emplace_back(left);
		}
	}
}

vector<int> Solution::findSubstring(string s, vector<string>& words) {
	int sn = s.size();
	int wsSize = words.size(), wSize = words[0].size();

	unordered_map<string, int> wCnt;
	vector<int> result;
	for (auto& word : words) ++wCnt[word];

	for (int i = 0 ; i < wSize ; ++i) {
		sliding_window(i, s, wSize, wsSize, sn, result, wCnt);
	}

	return result;
}


