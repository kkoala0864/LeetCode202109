#include <Solution.h>

int main(void) {
	// [16,14,null,4,15,1]
	// [10,6,2,9]
	TreeNode *root = new TreeNode(16);
	root->left = new TreeNode(14);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(15);
	root->left->left->left = new TreeNode(1);
	vector<int> queries = {10,6,2,9};
	Solution *test = new Solution();
	auto result = test->closestNodes(root, queries);
	for (const auto& v : result) {
		for (const auto& x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
