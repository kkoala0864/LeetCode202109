#include <Solution.h>
#include <iostream>

TreeNode* contruct(const vector<int>& nums, int start, int end) {
	if (start > end) return nullptr;
	if (start == end) return new TreeNode(nums[start]);
	int mid = (start + end) / 2;

	TreeNode* node = new TreeNode(nums[mid]);
	node->left = contruct(nums, start, mid -1);
	node->right = contruct(nums, mid + 1, end);
	return node;
}

TreeNode* Solution::sortedArrayToBST(vector<int>& nums) {
	return contruct(nums, 0, nums.size() - 1);
}
