#include <Solution.h>

int main(void) {
	// [2,1,3]
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	Solution *test = new Solution();
	auto result = test->serialize(root);
	cout << result << endl;
	auto newRoot = test->deserialize(result);
	return 0;
}
