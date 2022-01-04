#include <Solution.h>
#include <iostream>

bool isSameTree2(TreeNode* p, TreeNode* q) {
	if ((p && !q) || (!p && q)) return false;
	if (!p && !q) return true;
	if (p->val != q->val) return false;
	return isSameTree2(p->left, q->left) && isSameTree2(p->right, q->right);
}

