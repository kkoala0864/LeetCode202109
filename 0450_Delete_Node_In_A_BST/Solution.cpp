#include <Solution.h>
#include <iostream>

TreeNode* Solution::deleteNode(TreeNode* root, int key) {
	if (!root) return root;
	TreeNode* remove = root;
	TreeNode* prev = nullptr;
	while (remove) {
		if (remove->val == key) break;
		else if (remove->val < key) {
			prev = remove;
			remove = remove->right;
		} else {
			prev = remove;
			remove = remove->left;
		}
	}

	if (!remove) return root;
	TreeNode* newNode = remove->right ? remove->right : remove->left;
	if (newNode && newNode == remove->right) {
		if (remove->left && newNode->left) {
			TreeNode* append = remove->left;
			while (append->right) {
				append = append->right;
			}
			append->right = newNode->left;
		}
		if (remove->left) newNode->left = remove->left;
	}
	if (prev) {
		remove->val > prev->val ? prev->right = newNode : prev->left = newNode;
	} else {
		root = newNode;
	}
	return root;
}
