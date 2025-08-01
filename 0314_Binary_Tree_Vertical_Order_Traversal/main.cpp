#include <Solution.h>

int main(void) {
	// [3,9,20,null,null,15,7]
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	Solution *test = new Solution();
	auto result = test->verticalOrder(root);
	for (const auto &vec : result) {
		for (const auto &val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
