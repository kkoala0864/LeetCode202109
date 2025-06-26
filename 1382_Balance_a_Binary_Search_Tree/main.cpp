#include <Solution.h>

int main(void) {
	//[1,null,2,null,3,null,4,null,null]
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(3);
	root->right->right->right = new TreeNode(4);
	Solution *test = new Solution();
	auto result = test->balanceBST(root);
	return 0;
}
