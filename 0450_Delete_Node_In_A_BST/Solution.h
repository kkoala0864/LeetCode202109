struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	public :
		Solution() {}
		TreeNode* deleteNode(TreeNode* root, int key);
	private :
		virtual ~Solution() {}
		Solution& operator=(const Solution& source);
		Solution(const Solution&);
};

