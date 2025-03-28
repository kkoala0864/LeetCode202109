#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	TreeNode *deleteNode(TreeNode *root, int key);
	TreeNode *deleteNode2(TreeNode *root, int key);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
