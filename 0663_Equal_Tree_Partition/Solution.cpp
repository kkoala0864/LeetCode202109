#include <Solution.h>

int getSum(TreeNode* node) {
	if (!node) return 0;
	int cur = node->val;
	cur += getSum(node->left);
	cur += getSum(node->right);
	return cur;
}

int check(TreeNode* node, const int& target, bool& result) {
	if (!node) return 0;
	int sum = node->val;

	if (node->left) {
		int ls = check(node->left, target, result);
		result |= (ls == target);
		sum += ls;
	}
	if (node->right) {
		int rs = check(node->right, target, result);
		result |= (rs == target);
		sum += rs;
	}

	return sum;
}

bool Solution::checkEqualTree(TreeNode* root) {
	int sum = getSum(root);
	if (sum & 1) return false;
	int target = sum >> 1;
	bool result = false;
	check(root, target, result);
	return result;
}
