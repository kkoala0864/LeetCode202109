#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;

// p and q in different subtree
// p or q is currnet node and the other is in subtree

/*
bool DFS(TreeNode* root, int target, vector<TreeNode*>& path) {
        if (!root) return false;

        path.emplace_back(root);
        if (root->val == target) {
                return true;
        }
        if (!DFS(root->left, target, path) && !DFS(root->right, target, path)) {
                path.pop_back();
                return false;
        }
        return true;
}

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = nullptr;
        vector<TreeNode*> pRecord;
        vector<TreeNode*> qRecord;
        DFS(root, p->val, pRecord);
        DFS(root, q->val, qRecord);
        int i = 0;
        for (; i < min(pRecord.size(), qRecord.size()) ; ++i) {
                if (qRecord[i] != pRecord[i]) break;
        }

        return pRecord[i-1];
}
*/
TreeNode *Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (!root)
		return nullptr;
	if (root == p || root == q)
		return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left && right)
		return root;
	return left ? left : right;
}
