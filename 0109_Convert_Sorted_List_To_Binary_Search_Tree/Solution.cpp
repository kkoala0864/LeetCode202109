#include <Solution.h>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;

TreeNode* construct(const vector<int>& nums, int start, int end) {
	if (start > end) return nullptr;
	int mid = (start + end) / 2;
	TreeNode* node = new TreeNode(nums[mid]);
	node->left = construct(nums, start, mid - 1);
	node->right = construct(nums, mid+1, end);
	return node;
}

TreeNode* Solution::sortedListToBST(ListNode* head) {
	vector<int> nums;
	ListNode* iter = head;
	while (iter) {
		nums.emplace_back(iter->val);
		iter = iter->next;
	}

	return construct(nums, 0, nums.size() - 1);
}
