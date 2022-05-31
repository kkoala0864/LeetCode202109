#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<int> Solution::findSubstring(string s, vector<string>& words) {
	vector<int> result;
	if (words.empty()) return result;
	int size = words[0].size();
	int totalSize = size * words.size();
	if (s.size() < totalSize) return result;
	unordered_map<string, int> cnt;
	vector<bool> firstC(26, false);

	for (const auto& word : words) {
		++cnt[word];
		firstC[word[0]-'a'] = true;
	}

	for (int i = 0 ; i < (s.size() - totalSize + 1) ; ++i) {
		if (!firstC[s[i]-'a']) continue;
		unordered_map<string, int> cntTmp = cnt;
		int offset = 0;
		while (offset < totalSize) {
			string cur = s.substr(i + offset, size);
			if (cntTmp.find(cur) == cntTmp.end() || cntTmp[cur] == 0) break;
			--cntTmp[cur];
			offset += size;
		}
		if (offset == totalSize) result.emplace_back(i);
	}
	return result;
}
