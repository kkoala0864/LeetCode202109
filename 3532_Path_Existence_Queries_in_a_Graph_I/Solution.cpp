#include <Solution.h>
#include <iostream>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

vector<bool> Solution::pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
	vector<int> root;
	for (int i = 0 ; i < nums.size() ; ++i) root.emplace_back(i);

	for (int i = 0 ; i < nums.size() -1 ; ++i) {
		int lr = find(root, i);
		int rr = find(root, i + 1);
		if (lr == rr) continue;
		if (abs(nums[i] - nums[i+1]) > maxDiff) continue;
		root[lr] = root[rr] = min(lr, rr);
	}

	vector<bool> result;
	for (const auto& q : queries) {
		result.emplace_back(find(root, q[0]) == find(root, q[1]));
	}
	return result;
}
