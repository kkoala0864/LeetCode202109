#include <vector>

using std::vector;

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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
	TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder);
	TreeNode *buildTree3(vector<int> &preorder, vector<int> &inorder);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
