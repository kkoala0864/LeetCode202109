#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::min;
using std::unordered_map;
using std::pair;

int findPrefix(const string& lhs, const string& rhs) {
	int maxLen = min(lhs.size(), rhs.size());
	for (int len = maxLen; len > 0; --len) {
		if (lhs.compare(lhs.size() - len, len, rhs, 0, len) == 0) {
			return len;
		}
	}
	return 0;
}

string Solution::shortestSuperstring(vector<string>& words) {
	int size = words.size();
	vector<vector<int>> prefix(size, vector<int>(size, 0));

	for (int i = 0 ; i < words.size() ; ++i) {
		for (int j = 0 ; j < words.size() ; ++j) {
			if (i == j) continue;
			prefix[i][j] = findPrefix(words[i], words[j]);
		}
	}

	vector<unordered_map<int, pair<int, vector<int>>>> dp(size), next(size);
	for (int i = 0 ; i < words.size() ; ++i) {
		dp[i][1 << i] = pair<int, vector<int>>(0, vector<int>(1, i));
	}

	for (int i = 1 ; i < words.size() ; ++i) {
		for (int j = 0 ; j < words.size() ; ++j) {
			for (int k = 0 ; k < words.size() ; ++k) {
				if (j == k) continue;
				for (const auto& e : dp[k]) {
					if (e.first & (1 << j)) continue;
					int idx = e.first | (1 << j);
					if (next[j].count(idx) == 0 || (next[j][idx].first < (e.second.first + prefix[k][j]))) {
						next[j][idx].first = e.second.first + prefix[k][j];
						next[j][idx].second = e.second.second;
						next[j][idx].second.emplace_back(j);
					}
				}
			}
		}
		dp = next;
		next = vector<unordered_map<int, pair<int, vector<int>>>>(size);
	}
	int maxV = -1;
	vector<int> seq;
	for (const auto& v : dp) {
		if (v.begin()->second.first > maxV) {
			maxV = v.begin()->second.first;
			seq = v.begin()->second.second;
		}
	}
	string result = words[seq[0]];
	for (int i = 1 ; i < seq.size() ; ++i) {
		result += words[seq[i]].substr(prefix[seq[i-1]][seq[i]]);
	}
	return result;
}
