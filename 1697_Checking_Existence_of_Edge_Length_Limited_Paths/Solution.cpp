#include <Solution.h>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

vector<bool> Solution::distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
	vector<int> root;
	for (int i = 0 ; i < n ; ++i) root.emplace_back(i);
	for (int i = 0 ; i < queries.size() ; ++i) {
		queries[i].emplace_back(i);
	}

	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[2] < rhs[2];
	};
	sort(edgeList.begin(), edgeList.end(), cmp);
	sort(queries.begin(), queries.end(), cmp);

	int qi = 0;
	vector<bool> result(queries.size(), true);

	for (const auto& e : edgeList) {
		if (e[2] >= queries[qi][2]) {
			while (qi < queries.size() && queries[qi][2] <= e[2]) {
				int i1 = queries[qi][0];
				int i2 = queries[qi][1];
				result[queries[qi][3]] = (find(root, i1) == find(root, i2));
				++qi;
			}
			if (qi == queries.size()) break;
		}
		int lr = find(root, e[0]);
		int rr = find(root, e[1]);
		if (lr == rr) continue;
		root[lr] = root[rr] = min(lr, rr);
	}
	for (; qi < queries.size() ; ++qi) {
		int i1 = queries[qi][0];
		int i2 = queries[qi][1];
		result[queries[qi][3]] = (find(root, i1) == find(root, i2));
	}
	return result;
}
