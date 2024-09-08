#include <Solution.h>
#include <iostream>

bool recur(ListNode* ln, TreeNode* tn) {
	if (!ln) return true;
	if (!tn) return false;

	if (ln->val != tn->val) {
		return false;
	}
	ln = ln->next;
	if (!ln) return true;

	return recur(ln, tn->left) || recur(ln, tn->right);
}

bool dfs(ListNode* head, TreeNode* ri) {
	if (!ri) return false;
	if (ri->val == head->val) {
		if (recur(head, ri)) {
			return true;
		}
	}
	return dfs(head, ri->left) || dfs(head, ri->right);
}

bool Solution::isSubPath(ListNode* head, TreeNode* root) {
	return dfs(head, root);
}
