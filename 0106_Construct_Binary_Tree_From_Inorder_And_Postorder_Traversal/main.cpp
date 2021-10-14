#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

void PREORDER(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	PREORDER(root->left);
	PREORDER(root->right);
}

int main(void) {
	vector<int> inorder = {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	Solution* test = new Solution();
	TreeNode* result = test->buildTree(inorder, postorder);
	PREORDER(result);
	return 0;
}

