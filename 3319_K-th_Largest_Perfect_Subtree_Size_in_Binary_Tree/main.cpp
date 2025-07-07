#include <Solution.h>

int main(void) {
	// [5,3,6,5,2,5,7,1,8,null,null,6,8]
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(2);
	root->right->right = new TreeNode(5);
	root->right->left = new TreeNode(7);
	root->left->left->left = new TreeNode(1);
	root->left->left->right = new TreeNode(8);
	root->right->left->left = new TreeNode(6);
	root->right->left->right = new TreeNode(8);
	Solution *test = new Solution();
	int k = 2;
	cout << test->kthLargestPerfectSubtree(root, k) << endl;
	return 0;
}
