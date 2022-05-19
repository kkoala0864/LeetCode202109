struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderMorris(TreeNode* root) {
	TreeNode* cur = root, *prev = nullptr;
	while (cur) {
		if (!cur->left) {
			cout << cur->val << endl;
			cur = cur->right;
		} else {
			// find predecessor
			prev = cur->left;
			while (prev->right && prev->right != cur) {
				prev = prev->right;
			}
			if (!prev->right) {
				prev->right = cur;
				cur = cur->left;
			} else {
				prev->right = nullptr;
				cout << cur->val << endl;
				cur = cur->right;
			}
		}
	}
}
