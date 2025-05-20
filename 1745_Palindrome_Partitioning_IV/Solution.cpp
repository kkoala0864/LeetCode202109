#include <Solution.h>

vector<int> getManacher(const string& s) {
	string tmp(1, '#');
	for (const auto& c : s) {
		tmp.push_back(c);
		tmp.push_back('#');
	}

	vector<int> p(tmp.size(), 0);
	int mr = -1;
	int cr = -1;
	for (int i = 0 ; i < tmp.size() ; ++i) {
		if (i <= mr) {
			int j = 2 * cr - i;
			p[i] = min(p[j], mr - i);
		}

		while (i + p[i] < tmp.size() && i - p[i] >= 0 && tmp[i + p[i]] == tmp[i-p[i]]) {
			++p[i];
		}

		--p[i];
		if (i + p[i] > mr) {
			mr = i + p[i];
			cr = i;
		}
	}
	return p;
}

bool isPalin(int l, int r, vector<int>& p) {
	int mid = l + r + 1;
	int rr = 2 * r + 1;
	return (mid + p[mid]) >= rr;
}

bool Solution::checkPartitioning(string s) {
	vector<bool> dp(s.size() + 1, false);
	vector<int> p = getManacher(s);
	dp[0] = true;

	for (int pi = 0 ; pi < 3 ; ++pi) {
		auto next = dp;
		for (int i = 0 ; i < s.size() ; ++i) {
			for (int j = i ; j >= pi ; --j) {
				if (!dp[j]) continue;
				next[i+1] = isPalin(j, i, p);
				if (next[i+1]) break;
			}
		}
		dp = move(next);
	}
	return dp.back();
}
