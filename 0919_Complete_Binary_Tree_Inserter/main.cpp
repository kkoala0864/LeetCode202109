#include <Solution.h>

int main(void) {
	// ["CBTInserter", "insert", "insert", "get_root"]
	// [[[1, 2]], [3], [4], []]
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	CBTInserter *test = new CBTInserter(root);
	cout << test->insert(3) << endl;
	cout << test->insert(4) << endl;
	TreeNode* result = test->get_root();
	cout << result->val << endl;
	return 0;
}
