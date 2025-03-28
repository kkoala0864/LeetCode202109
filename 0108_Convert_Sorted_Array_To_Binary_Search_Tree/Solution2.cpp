#include <Solution.h>
#include <iostream>

TreeNode *construct(vector<int> &nums, int start, int end) {
	if (start > end)
		return nullptr;

	if (start == end)
		return new TreeNode(nums[start]);

	int mid = (end - start) / 2 + start;
	TreeNode *node = new TreeNode(nums[mid]);
	node->left = construct(nums, start, mid - 1);
	node->right = construct(nums, mid + 1, end);
	return node;
}

TreeNode *Solution::sortedArrayToBST2(vector<int> &nums) {
	return construct(nums, 0, nums.size() - 1);
}
