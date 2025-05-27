#include <Solution.h>

void dfs(int node, int k, string& result, vector<bool>& visited, int mod) {
	for (int i = 0 ; i < k ; ++i) {
		int nn = node * k + i;
		if (visited[nn]) continue;
		visited[nn] = true;
		dfs(nn % mod, k, result, visited, mod);
		result.push_back(i + '0');
	}
}

string Solution::crackSafe(int n, int k) {
	if (n == 1) {
		string result;
		for (int i = 0 ; i < k ; ++i) {
			result.push_back(i + '0');
		}
		return result;
	}

	int mod = (int)pow(k, n-1);
	int edges = mod * k;
	vector<bool> visited(edges, false);

	string result;

	dfs(0, k, result, visited, mod);
	reverse(result.begin(), result.end());
	result = string(n-1, '0') + result;
	return result;
}
