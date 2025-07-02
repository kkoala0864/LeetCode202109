#include <data_type.h>

class CBTInserter {
public:

	void dfs(int idx, TreeNode* node, unordered_map<int, TreeNode*>& idxs, int& farIdx) {
		if (!node) return;
		idxs[idx] = node;
		farIdx = max(farIdx, idx);
		dfs(2 * idx + 1, node->left, idxs, farIdx);
		dfs(2 * idx + 2, node->right, idxs, farIdx);
	}
	CBTInserter(TreeNode* root) {
		farIdx = 0;
		dfs(0, root, idxs, farIdx);
		++farIdx;
	}

	int insert(int val) {
		TreeNode* node = new TreeNode(val);
		idxs[farIdx] = node;

		TreeNode* parent = nullptr;
		int v = farIdx++;
		if (v & 1) {
			v -= 1;
			v = v >> 1;
			parent = idxs[v];
			parent->left = node;
		} else {
			v -= 2;
			v = v >> 1;
			parent = idxs[v];
			parent->right = node;
		}
		return parent->val;
	}

	TreeNode* get_root() {
		return idxs[0];
	}

private:
	unordered_map<int, TreeNode*> idxs;
	int farIdx;
	virtual ~CBTInserter() {
	}
	CBTInserter &operator=(const CBTInserter &source);
	CBTInserter(const CBTInserter &);
};
