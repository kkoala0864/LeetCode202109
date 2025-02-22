#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

void preorder(TreeNode* root) {
	if (!root) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

int main(void) {
	string input = "1-2--3--4-5--6--7";
	Solution* test = new Solution();
	auto result = test->recoverFromPreorder(input);
	preorder(result);
	cout << endl;
	return 0;

}

