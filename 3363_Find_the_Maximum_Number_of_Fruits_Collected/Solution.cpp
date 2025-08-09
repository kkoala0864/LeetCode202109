#include <Solution.h>

int getRUMax(const vector<vector<int>>& fruits, const vector<int>& loff) {
	int n = fruits.size();
	vector<int> cur(n, 0);
	cur.back() = fruits[0].back();

	vector<int> offset = {-1, 0, 1};
	for (int i = 1 ; i < n ; ++i) {
		vector<int> next(n, 0);
		for (int j = n - loff[i] ; j < n ; ++j) {
			for (const auto& o : offset) {
				int lx = i - 1;
				int ly = j + o;
				if (ly < n - loff[i-1] || ly >= n) continue;
				next[j] = max(next[j], cur[ly] + fruits[i][j]);
			}
		}
		cur = std::move(next);
	}
	return cur.back();
}

int getLDMax(const vector<vector<int>>& fruits, const vector<int>& loff) {
	int n = fruits.size();
	vector<int> cur(n, 0);
	cur.back() = fruits[n-1][0];

	vector<int> offset = {-1, 0, 1};
	for (int j = 1 ; j < n ; ++j) {
		vector<int> next(n, 0);
		for (int i = n - loff[j] ; i < n ; ++i) {
			for (const auto& o : offset) {
				int lx = i + o;
				int ly = j - 1;
				if (lx < n - loff[j-1] || lx >= n) continue;
				next[i] = max(next[i], cur[lx] + fruits[i][j]);
			}
		}
		cur = std::move(next);
	}
	return cur.back();
}

int Solution::maxCollectedFruits(vector<vector<int>>& fruits) {
	int n = fruits.size();
	int result = 0;
	for (int i = 0 ; i < n ; ++i) {
		result += fruits[i][i];
		fruits[i][i] = 0;
	}

	vector<int> loff;
	int i = 1;
	for (; i <= n/2 ; ++i) {
		loff.emplace_back(i);
	}
	if (n & 1) {
		loff.emplace_back(i);
	}
	--i;
	for (; i >= 1 ; --i) {
		loff.emplace_back(i);
	}
	result += getRUMax(fruits, loff);
	result += getLDMax(fruits, loff);
	return result;
}
