#include <Solution.h>

int Solution::largestPathValue(string colors, vector<vector<int>> &edges) {
	int size = colors.size();
	vector<vector<int>> connect(size, vector<int>());
	vector<int> indegree(size, 0);

	for (const auto& e : edges) {
		connect[e[0]].emplace_back(e[1]);
		++indegree[e[1]];
		if (e[0] == e[1]) return -1;
	}

	int visited = 0;
	vector<vector<int>> cnts(size, vector<int>(26, 0));

	queue<int> que;
	for (int i = 0 ; i < size ; ++i) {
		if (indegree[i] == 0) {
			que.emplace(i);
			cnts[i][colors[i]-'a'] = 1;
			++visited;
		}
	}
	if (que.empty()) return -1;
	int result = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto& n : connect[cur]) {
			vector<int> tmp = cnts[cur];
			++tmp[colors[n]-'a'];
			for (int i = 0 ; i < 26 ; ++i) {
				cnts[n][i] = max(cnts[n][i], tmp[i]);
				result = max(result, cnts[n][i]);
			}
			--indegree[n];
			if (indegree[n] == 0) {
				++visited;
				if (visited > size) return -1;
				que.emplace(n);
			}
		}
	}
	return visited == size ? result : -1;
}
