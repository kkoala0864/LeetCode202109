#include <Solution.h>
#include <iostream>

TreeNode *construct(ListNode *&node, int size) {
	if (size <= 0)
		return nullptr;
	if (size == 1)
		return new TreeNode(node->val);

	int mid = size / 2 + 1;
	TreeNode *left = construct(node, mid - 1);
	node = node->next;
	TreeNode *ret = new TreeNode(node->val);
	ret->left = left;
	if (size - mid) {
		node = node->next;
		ret->right = construct(node, size - mid);
	}
	return ret;
}

TreeNode *Solution::sortedListToBST2(ListNode *head) {
	if (!head)
		return nullptr;

	ListNode *iter = head;
	int size = 0;
	while (iter) {
		++size;
		iter = iter->next;
	}
	return construct(head, size);
}
