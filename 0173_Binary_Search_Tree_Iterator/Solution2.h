#include <stack>

using std::stack;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
	public :
		BSTIterator(TreeNode* root) {
			while (root) {
				st.emplace(root);
				root = root->left;
			}
		}

		int next() {
			TreeNode* result = st.top();
			st.pop();
			if (result->right) {
				TreeNode* iter = result->right;
				while (iter) {
					st.emplace(iter);
					iter = iter->left;
				}
			}
			return result->val;
		}

		bool hasNext() {
			return !st.empty();
		}

    private :
		stack<TreeNode*> st;
		virtual ~BSTIterator() {}
		BSTIterator& operator=(const BSTIterator& source);
		BSTIterator(const BSTIterator&);
};


