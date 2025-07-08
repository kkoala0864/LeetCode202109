#include <Solution.h>

int main(void) {
	// [5,3,6,2,4,null,null,1]
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->left->left->left = new TreeNode(1);
	Solution *test = new Solution();
	auto result = test->inorderSuccessor(root, root->left->left->left);
	if (result == nullptr) {
		cout << "null" << endl;
	} else {
		cout << result->val << endl;
	}
	return 0;
}
