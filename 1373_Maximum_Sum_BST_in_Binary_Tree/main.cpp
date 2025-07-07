#include <Solution.h>

int main(void) {
	// [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(4);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(5);
	root->right->right->left = new TreeNode(4);
	root->right->right->right = new TreeNode(6);
	Solution *test = new Solution();
	cout << test->maxSumBST(root) << endl;
	return 0;
}
