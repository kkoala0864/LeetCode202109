#include <stack>

using std::stack;

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

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root) {
			st.emplace(root);
			root = root->left;
		}
	}

	int next() {
		auto cur = st.top();
		int result = cur->val;
		st.pop();
		cur = cur->right;
		while (cur) {
			st.emplace(cur);
			cur = cur->left;
		}
	}

	bool hasNext() {
		return !st.empty();
	}

private:
	stack<TreeNode *> st;
	virtual ~BSTIterator() {
	}
	BSTIterator &operator=(const BSTIterator &source);
	BSTIterator(const BSTIterator &);
};
