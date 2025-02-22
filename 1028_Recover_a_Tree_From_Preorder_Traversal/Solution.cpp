#include <Solution.h>
#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::vector;
using std::cout;
using std::endl;

TreeNode* Solution::recoverFromPreorder(string traversal) {
	if (traversal.empty()) return nullptr;
	vector<int> depth;
	vector<TreeNode*> val;

	int i = 0;
	while (i < traversal.size()) {
		int d = 0;
		int v = 0;
		while (i < traversal.size() && traversal[i] == '-') {
			++d;
			++i;
		}
		depth.emplace_back(d);
		while (i < traversal.size() && traversal[i] != '-') {
			v *= 10;
			v += (traversal[i] - '0');
			++i;
		}
		val.emplace_back(new TreeNode(v));
	}
	stack<int> st;
	st.emplace(0);

	for (int i = 1 ; i < depth.size() ; ++i) {
		while (!st.empty() && depth[st.top()] >= depth[i]) {
			st.pop();
		}

		if (val[st.top()]->left) val[st.top()]->right = val[i];
		else val[st.top()]->left = val[i];
		st.emplace(i);
	}
	return val[0];
}
