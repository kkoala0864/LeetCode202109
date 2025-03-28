#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

void serialize(TreeNode *node, vector<int> &vec) {
	if (!node)
		return;
	if (node->left)
		serialize(node->left, vec);
	vec.emplace_back(node->val);
	if (node->right)
		serialize(node->right, vec);
}

bool Solution::twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
	vector<int> v1, v2;
	serialize(root1, v1);
	serialize(root2, v2);

	int i1 = 0, i2 = v2.size() - 1;

	int sum = 0;
	while (i1 < v1.size() && i2 >= 0) {
		sum = v1[i1] + v2[i2];

		if (sum == target) {
			return true;
		} else if (sum < target) {
			++i1;
		} else {
			--i2;
		}
	}
	return false;
}
