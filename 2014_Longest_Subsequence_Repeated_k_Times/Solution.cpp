#include <Solution.h>

int getCnt(const string& s, const string& t) {
	int cnt = 0;
	int ti = 0;
	int ts = t.size();
	for (const auto& c : s) {
		if (c == t[ti]) {
			ti = (ti + 1) % ts;
			if (ti == 0) ++cnt;
		}
	}
	return cnt;
}

void dfs(string cur, int size, const string& s, vector<int>& cnt, vector<int>& need, int k, string& result) {
	if (!cur.empty() && cur.size() > result.size()) {
		int cnt = getCnt(s, cur);
		if (cnt >= k) {
			result = cur;
		}
	}

	if (cur.size() == size) {
		return;
	}

	for (int i = 25 ; i >= 0 ; --i) {
		++need[i];
		if (cnt[i] >= (need[i] * k)) {
			cur.push_back(i + 'a');
			dfs(cur, size, s, cnt, need, k, result);
			cur.pop_back();
		}
		--need[i];
	}
}

string Solution::longestSubsequenceRepeatedK(string s, int k) {
	int ps = (s.size() / k);

	vector<int> cnt(26, 0);
	for (const auto& c : s) ++cnt[c-'a'];

	string result;
	vector<int> need(26, 0);
	dfs("", ps, s, cnt, need, k, result);
	return result;
}
