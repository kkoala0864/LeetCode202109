#include <Solution.h>

void dfs(int v, int n, vector<int>& result) {
	if (v > n) return;
	result.emplace_back(v);
	v *= 10;
	for (int i = 0 ; i < 10 ; ++i) {
		dfs(v + i, n, result);
	}
}

vector<int> Solution::lexicalOrder(int n) {
	vector<int> result;
	for (int i = 1 ; i <= min(9, n) ; ++i) {
		dfs(i, n, result);
	}
	return result;

}
