#include <Solution.h>

int main(void) {
	// [4,2,5,1,3]
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	double target = 3.714286;
	int k = 2;
	Solution *test = new Solution();
	auto result = test->closestKValues(root, target, k);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
