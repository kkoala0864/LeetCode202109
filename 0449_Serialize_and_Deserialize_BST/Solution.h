#include <data_type.h>

class Solution {
public:
	Solution() {
	}

	string serialize(TreeNode* root) {
		if (!root) return "";
		string result = to_string(root->val);
		string ls = serialize(root->left);
		if (!ls.empty()) {
			result += "," + ls;
		}
		string rs = serialize(root->right);
		if (!rs.empty()) {
			result += "," + rs;
		}
		return result;
	}

	vector<int> parse(const string& s) {
		vector<int> result;
		int start = 0;
		int idx = s.find(",");
		while (idx != string::npos) {
			string vs = s.substr(start, idx);
			result.emplace_back(stoi(vs));
			start = idx + 1;
			idx = s.find(",", start);
		}
		string vs = s.substr(start);
		result.emplace_back(stoi(vs));
		return result;
	}

	TreeNode* dfs(const vector<int>& vl, int l, int r) {
		if (l > r) return nullptr;
		if (l == r) return new TreeNode(vl[l]);

		TreeNode* node = new TreeNode(vl[l]);
		int rstart = l + 1;
		for (; rstart <= r ; ++rstart) {
			if (vl[rstart] > vl[l]) break;
		}
		node->left = dfs(vl, l + 1, rstart - 1);
		node->right = dfs(vl, rstart, r);
		return node;
	}

	TreeNode* deserialize(string data) {
		if (data.empty()) return nullptr;
		vector<int> vl = parse(data);
		return dfs(vl, 0, vl.size() - 1);
	}

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
