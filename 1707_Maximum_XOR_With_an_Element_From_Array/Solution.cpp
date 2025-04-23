#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

// 19 : 00010011
//      11101100

void addValue(vector<int>& nums, int& idx, int maxv, TrieNode* root) {
	while (idx < nums.size() && nums[idx] <= maxv) {
		TrieNode* iter = root;
		for (int i = 31 ; i >= 0 ; --i) {
			int b = (nums[idx] >> i) & 1;
			if (!iter->children[b]) {
				iter->children[b] = new TrieNode();
			}
			iter = iter->children[b];
		}
		iter->val = nums[idx];
		++idx;
	}
}

vector<int> Solution::maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
	for (int i = 0 ; i < queries.size() ; ++i) {
		queries[i].emplace_back(i);
	}
	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
	};
	sort(nums.begin(), nums.end());
	sort(queries.begin(), queries.end(), cmp);
	TrieNode* root = new TrieNode();
	vector<int> result(queries.size(), -1);

	int idx = 0;
	for (const auto& q : queries) {
		if (q[1] < nums[0]) continue;
		addValue(nums, idx, q[1], root);

		auto iter = root;
		int rx = ~q[0];
		for (int i = 31 ; i >= 0 ; --i) {
			int b = (rx >> i) & 1;
			if (iter->children[b]) {
				iter = iter->children[b];
			} else {
				iter = iter->children[b == 0 ? 1 : 0];
			}
		}
		result[q[2]] = q[0] ^ iter->val;
	}
	return result;
}
