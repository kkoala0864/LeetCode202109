#include <string>
#include <queue>
#include <iostream>

using std::string;
using std::to_string;
using std::cout;
using std::endl;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public :
        Solution() {}

	string _serialize(TreeNode* root) {
		if (!root) return "null";
		string numStr = to_string(root->val);
		numStr += ","+_serialize(root->left);
		numStr += ","+_serialize(root->right);
		return numStr;
	}

	string serialize(TreeNode* root) {
		if (!root) return "";
		return _serialize(root);
	}

	TreeNode* deserializeTree(const string& data, int& index) {
		int size = data.size();
		if (index >= size) return nullptr;

		int left = index + 1;
		index = left;
		while (data[index] != ',' && index < data.size()) {
			++index;
		}

		string numStr = data.substr(left, index - left);

		if (numStr == "null") return nullptr;
		else {
			int num = stoi(numStr);
			TreeNode* node = new TreeNode(num);
			node->left = deserializeTree(data, index);
			node->right = deserializeTree(data, index);
			return node;
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int idx = -1;
		return deserializeTree(data, idx);
	}
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

