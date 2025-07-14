#include <Solution.h>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

vector<int> unionFind(vector<vector<int>>& edges, int exclude) {
	int n = edges.size();
	vector<int> root(1,0);
	for (int i = 1 ; i <= n ; ++i) {
		root.emplace_back(i);
	}

	for (int i = 0 ; i < edges.size() ; ++i) {
		if (exclude == i) continue;
		int lr = find(root, edges[i][0]);
		int rr = find(root, edges[i][1]);
		if (lr == rr) return edges[i];
		root[lr] = root[rr] = min(lr, rr);
	}

	return vector<int>({-1, -1});
}

vector<int> Solution::findRedundantDirectedConnection(vector<vector<int>>& edges) {
	int n = edges.size();
	vector<vector<int>> parent(n + 1, vector<int>());
	int dpN = -1;
	for (int i = 0 ; i < n ; ++i) {
		parent[edges[i][1]].emplace_back(i);
		if (parent[edges[i][1]].size() > 1) {
			dpN = edges[i][1];
			break;
		}
	}

	if (dpN == -1) return unionFind(edges, -1);
	else {
		while (!parent[dpN].empty()) {
			int i = parent[dpN].back();
			parent[dpN].pop_back();
			auto tmp = unionFind(edges, i);
			if (tmp[0] == -1) return edges[i];
		}
	}
	return vector<int>({-1, -1});

}
