#include <Solution.h>

int getDis(int a, int b) {
	int a1 = a / 6;
	int a2 = a % 6;
	int b1 = b / 6;
	int b2 = b % 6;
	return abs(a1 - b1) + abs(a2 - b2);
}

int dfs(const string& s, int idx, int l1, int l2, vector<vector<vector<int>>>& cache) {
	if (cache[idx][l1][l2] != INT_MAX) return cache[idx][l1][l2];

	int v1 = l1 == 26 ? 0 : getDis(l1, s[idx] - 'A');
	int v2 = l2 == 26 ? 0 : getDis(l2, s[idx] - 'A');

	if (idx == (s.size() - 1)) {
		return cache[idx][l1][l2] = min(v1, v2);
	}

	v1 += dfs(s, idx + 1, s[idx] - 'A', l2, cache);
	v2 += dfs(s, idx + 1, l1, s[idx] - 'A', cache);
	return cache[idx][l1][l2] = min(v1, v2);
}

int Solution::minimumDistance(string word) {
	int size = word.size();
	vector<vector<vector<int>>> cache(size, vector<vector<int>>(27, vector<int>(27, INT_MAX)));
	return dfs(word, 0, 26, 26, cache);

}
