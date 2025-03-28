#include <Solution.h>
#include <iostream>
#include <math.h>
/*
int bsearch(int start, int end, TreeNode* node, int height) {
        if (!node->left && !node->right) {
                return height == 0 ? start : -1;
        } else if (node->left && !node->right) {
                return start;
        } else if (!node->right && node->right) {
                return end;
        }

        int lr = bsearch(start, (start + end)/2, node->left, height - 1);
        int rr = bsearch((start+end)/2 + 1, end, node->right, height - 1);
        return max(lr, rr);
}

int Solution::countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* iter = root;
        int height = 0;
        while (iter) {
                ++height;
                iter = iter->left;
        }
        if (height == 1) return 1;
        int lastFullNumber = pow(2, height-1);
        int levelNodeSize = bsearch(1, lastFullNumber, root, height-1);
        return pow(2, height-1) - 1 + levelNodeSize;
}*/

int Solution::countNodes(TreeNode *root) {
	TreeNode *left = root, *right = root;
	int lh = 0, rh = 0;
	while (left) {
		++lh;
		left = left->left;
	}
	while (right) {
		++rh;
		right = right->right;
	}

	if (lh == rh) {
		return pow(2, lh) - 1;
	}

	return 1 + countNodes(root->left) + countNodes(root->right);
}
