#include <Solution.h>

void inorder(TreeNode *root) {
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

int main(void) {
	// [4,1,3,null,null,2]
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(2);
	int val = 5;
	Solution *test = new Solution();
	TreeNode *result = test->insertIntoMaxTree(root, val);
	inorder(result);
	cout << endl;
	return 0;
}
