#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(20);
	Solution *test = new Solution();
	auto ret = test->printTree(root);
	for (const auto &iter : ret) {
		for (const auto &val : iter) {
			cout << (val == "" ? "0" : val) << " ";
		}
		cout << endl;
	}
	return 0;
}
