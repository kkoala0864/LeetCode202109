#include <Solution.h>
#include <iostream>

TreeNode *dfs(vector<int> &nums, int start, int end) {
	if (start > end)
		return nullptr;
	if (start == end)
		return new TreeNode(nums[start]);

	int mid = start + ((end - start) >> 1);
	TreeNode *node = new TreeNode(nums[mid]);
	node->left = dfs(nums, start, mid - 1);
	node->right = dfs(nums, mid + 1, end);
	return node;
}

TreeNode *Solution::sortedArrayToBST3(vector<int> &nums) {
	return dfs(nums, 0, nums.size() - 1);
}
