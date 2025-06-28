#include <Solution.h>

int main(void) {
	// [1,2,3,null,4,5,6]
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);

	Solution *test = new Solution();
	cout << test->findNearestRightNode(root, root->left->right)->val << endl; // 3

	return 0;
}
