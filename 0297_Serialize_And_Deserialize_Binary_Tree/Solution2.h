#include <string>
#include <queue>
#include <iostream>

using std::string;
using std::to_string;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public :
        Solution() {}

	void _serial(TreeNode* node, string& result) {
		if (!node) {
			result += "null,";
			return;
		}
		result += to_string(node->val) + ",";
		_serial(node->left, result);
		_serial(node->right, result);
	}

	string serialize(TreeNode* root) {
		string result("");
		_serial(root, result);
		return result;
	}

	TreeNode* deserial(string& data, int& index) {
		if (index >= data.size()) return nullptr;
		int start = index;
		while (data[index] != ',') ++index;
		string valStr = data.substr(start, index - start);
		if (valStr == "null") return nullptr;
		TreeNode* left = deserial(data, ++index);
		TreeNode* right = deserial(data, ++index);
		TreeNode* node = new TreeNode(stoi(valStr));
		node->left = left;
		node->right = right;
		return node;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int index = 0;
		return deserial(data, index);
	}
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

