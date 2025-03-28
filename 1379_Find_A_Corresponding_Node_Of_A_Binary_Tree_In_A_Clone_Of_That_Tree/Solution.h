struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x)
	    : val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
	Solution() {
	}
	TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
