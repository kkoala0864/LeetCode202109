#include <queue>
#include <stack>

using std::stack;
using std::queue;

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
		void traverse(TreeNode* node) {
			if (!node) return;
			traverse(node->left);
			_inorder.emplace(node->val);
			traverse(node->right);
		}
		BSTIterator(TreeNode* root) {
			traverse(root);
		}

		int next() {
			int val = _inorder.front();
			_inorder.pop();
			return val;
		}

		bool hasNext() {
			return !_inorder.empty();
		}
    private :
	queue<int> _inorder;
        virtual ~BSTIterator() {}
        BSTIterator& operator=(const BSTIterator& source);
        BSTIterator(const BSTIterator&);
};

class BSTIterator {
	public :
		BSTIterator(TreeNode* root) {
			GetLeftNodes(root);
		}

		int next() {
			TreeNode* node = _st.top();
			_st.pop();
			if (node->right) GetLeftNodes(node->right);
			cout << node->val << endl;
			return node->val;
		}

		bool hasNext() {
			return !_st.empty();
		}

		void GetLeftNodes(TreeNode* node) {
			while (node) {
				_st.emplace(node);
				node = node->left;
			}
		}
    private :
	stack<TreeNode*> _st;
        virtual ~BSTIterator() {}
        BSTIterator& operator=(const BSTIterator& source);
        BSTIterator(const BSTIterator&);
};


