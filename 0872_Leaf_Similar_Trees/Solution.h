struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode()
	    : val(0), left(nullptr), right(nullptr) {
	}
	TreeNode(int x)
	    : val(x), left(nullptr), right(nullptr) {
	}
	TreeNode(int x, TreeNode *left, TreeNode *right)
	    : val(x), left(left), right(right) {
	}
};

class Solution {
public:
	Solution() {
	}
	bool leafSimilar(TreeNode *root1, TreeNode *root2);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
