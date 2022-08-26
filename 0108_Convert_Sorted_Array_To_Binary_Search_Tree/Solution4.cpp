#include <Solution.h>
#include <iostream>

TreeNode* dfs2(vector<int>& nums, int start, int end) {
	if (start > end) return nullptr;
	if (start == end) return new TreeNode(nums[start]);

	int mid = (end + start) >> 1;

	TreeNode* node = new TreeNode(nums[mid]);

	node->left = dfs2(nums, start, mid - 1);
	node->right = dfs2(nums, mid + 1, end);
	return node;
}

TreeNode* Solution::sortedArrayToBST4(vector<int>& nums) {
	return dfs2(nums, 0, nums.size() - 1);
}
