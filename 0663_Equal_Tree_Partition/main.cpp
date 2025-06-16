#include <Solution.h>

int main(void) {
	// [0, -1, 1]
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(-1);
	root->right = new TreeNode(1);
	Solution *test = new Solution();
	cout << test->checkEqualTree(root) << endl;
	return 0;
}
