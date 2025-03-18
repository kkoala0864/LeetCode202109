#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	//[5,1,5,5,5,null,5]
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(5);
	Solution* test = new Solution();
	cout << test->countUnivalSubtrees(root) << endl;
	return 0;
}

