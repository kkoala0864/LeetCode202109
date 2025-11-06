#include <Solution.h>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

vector<int> Solution::processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
	vector<int> root;
	vector<set<int>> group(c, set<int>());

	for (int i = 0 ; i < c ; ++i) {
		root.emplace_back(i);
		group[i].emplace(i);
	}
	for (const auto& c : connections) {
		int lr = find(root, c[0]-1);
		int rr = find(root, c[1]-1);
		if (lr == rr) continue;
		int nr = min(lr, rr);
		int ar = max(lr, rr);

		root[lr] = root[rr] = nr;
		for (const auto& v : group[ar]) {
			group[nr].emplace(v);
		}
	}
	vector<int> result;
	for (const auto& q : queries) {
		int r = find(root, q[1] - 1);
		if (q[0] == 1) {
			if (group[r].count(q[1] - 1)) result.emplace_back(q[1]);
			else {
				result.emplace_back(group[r].empty() ? -1 : *(group[r].begin()) + 1);
			}
		} else {
			group[r].erase(q[1] - 1);
		}
	}
	return result;
}
