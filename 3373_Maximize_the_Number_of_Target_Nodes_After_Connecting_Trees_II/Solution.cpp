#include <Solution.h>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

int dfs(int rn, int curNode, int lastNode, vector<vector<int>>& e, int level, int isEven, vector<int>& root) {
	int ret = (level % 2) == isEven;
	if (level % 2 == 0) {
		int lr = find(root, rn);
		int rr = find(root, curNode);
		root[lr] = root[rr] = min(lr, rr);
	}

	for (const auto& n : e[curNode]) {
		if (n == lastNode) continue;
		ret += dfs(rn, n, curNode, e, level + 1, isEven, root);
	}
	return ret;
}

vector<int> Solution::maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
	vector<int> c2(edges2.size() + 1, 0);
	vector<vector<int>> e1(edges1.size() + 1, vector<int>());
	vector<vector<int>> e2(edges2.size() + 1, vector<int>());
	vector<int> r1, r2;
	for (int i = 0 ; i < e1.size() ; ++i) r1.emplace_back(i);
	for (int i = 0 ; i < e2.size() ; ++i) r2.emplace_back(i);

	for (const auto& e : edges1) {
		e1[e[0]].emplace_back(e[1]);
		e1[e[1]].emplace_back(e[0]);
	}
	for (const auto& e : edges2) {
		e2[e[0]].emplace_back(e[1]);
		e2[e[1]].emplace_back(e[0]);
	}
	int max2 = 0;
	for (int i = 0 ; i < c2.size() ; ++i) {
		if (find(r2, i) != i) continue;
		max2 = max(max2, dfs(i, i, -1, e2, 0, 1, r2));
	}
	vector<int> c1(edges1.size() + 1, max2);
	for (int i = 0 ; i < c1.size() ; ++i) {
		if (find(r1, i) != i) {
			c1[i] = c1[find(r1, i)];
		} else {
			c1[i] += dfs(i, i, -1, e1, 0, 0, r1);
		}
	}
	return c1;

}
