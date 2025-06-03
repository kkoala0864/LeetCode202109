#include <Solution.h>

int Solution::maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
	int size = status.size();
	queue<int> que;
	vector<bool> visited(size, false);
	unordered_set<int> have;

	for (const auto& i : initialBoxes) {
		have.emplace(i);
		for (const auto& k : keys[i]) {
			status[k] = 1;
		}
	}

	int result = 0;
	for (int i = 0 ; i < size ; ++i) {
		if (status[i] == 1 && have.count(i)) {
			que.emplace(i);
			visited[i] = true;
			result += candies[i];
		}
	}
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto& b : containedBoxes[cur]) {
			if (visited[b]) continue;
			have.emplace(b);
			if (status[b] == 1) {
				result += candies[b];
				visited[b] = true;
				que.emplace(b);
			}
		}
		for (const auto& k : keys[cur]) {
			if (visited[k]) continue;
			status[k] = 1;
			if (have.count(k)) {
				result += candies[k];
				visited[k] = true;
				que.emplace(k);
			}
		}
	}
	return result;
}
