#include <Solution.h>

int main(void) {
	// [10,5,15,1,8,null,7]
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(8);
	root->right->right = new TreeNode(7);
	Solution *test = new Solution();
	cout << test->largestBSTSubtree(root) << endl;
	return 0;
}
