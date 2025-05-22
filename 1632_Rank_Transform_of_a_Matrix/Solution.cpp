#include <Solution.h>

int find(vector<int>& root, int idx) {
	if (root[idx] == -1) root[idx] = idx;
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

vector<vector<int>> Solution::matrixRankTransform(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	vector<int> root(m * n, -1);
	vector<int> indegree(m * n, 0);
	vector<vector<int>> next(m * n, vector<int>());

	for (int i = 0 ; i < m ; ++i) {
		vector<pair<int, int>> tmp;
		for (int j = 0 ; j < n ; ++j) {
			tmp.emplace_back(pair<int, int>(matrix[i][j], i * n + j));
		}
		sort(tmp.begin(), tmp.end());

		for (int j = 1 ; j < n ; ++j) {
			if (tmp[j].first == tmp[j-1].first) {
				int lr = find(root, tmp[j].second);
				int rr = find(root, tmp[j-1].second);
				if (lr == rr) continue;
				int minR = min(lr, rr);
				int maxR = max(lr, rr);
				root[lr] = root[rr] = minR;
			} else {
				next[tmp[j-1].second].emplace_back(tmp[j].second);
				++indegree[tmp[j].second];
			}
		}
	}

	for (int j = 0 ; j < n ; ++j) {
		vector<pair<int, int>> tmp;
		for (int i = 0 ; i < m ; ++i) {
			tmp.emplace_back(pair<int, int>(matrix[i][j], i * n + j));
		}
		sort(tmp.begin(), tmp.end());

		for (int i = 1 ; i < m ; ++i) {
			if (tmp[i].first == tmp[i-1].first) {
				int lr = find(root, tmp[i].second);
				int rr = find(root, tmp[i-1].second);
				if (lr == rr) continue;
				int minR = min(lr, rr);
				int maxR = max(lr, rr);
				root[lr] = root[rr] = minR;
			} else {
				next[tmp[i-1].second].emplace_back(tmp[i].second);
				++indegree[tmp[i].second];
			}
		}
	}
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			int key = i * n + j;
			int rkey = find(root, key);
			if (key != rkey) {
				indegree[rkey] += indegree[key];
				for (const auto& n : next[key]) {
					next[rkey].emplace_back(n);
				}
			}
		}
	}
	queue<int> que, nq;
	int level = 1;

	unordered_set<int> visited;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			int key = find(root, i * n + j);
			if (visited.count(key)) continue;
			visited.emplace(key);
			if (indegree[key] == 0) {
				que.emplace(key);
			}
		}
	}

	unordered_map<int, int> rank;
	while (!que.empty()) {
		int key = find(root, que.front());
		int x = key / n;
		int y = key % n;
		que.pop();
		rank[key] = level;

		for (const auto& n : next[key]) {
			int nkey = find(root, n);
			--indegree[nkey];
			if (indegree[nkey] == 0) {
				nq.emplace(nkey);
			}
		}
		if (que.empty()) {
			que = move(nq);
			++level;
		}
	}
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			matrix[i][j] = rank[find(root, i * n + j)];
		}
	}
	return matrix;
}
