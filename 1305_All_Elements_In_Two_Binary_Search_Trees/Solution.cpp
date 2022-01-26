#include <Solution.h>
#include <iostream>
#include <stack>
using std::stack;
/*
void inorder(TreeNode* node, vector<int>& list) {
	if (!node) return;

	inorder(node->left, list);
	list.emplace_back(node->val);
	inorder(node->right, list);
}

vector<int> Solution::getAllElements(TreeNode* root1, TreeNode* root2) {
	vector<int> list1, list2, result;
	inorder(root1, list1);
	inorder(root2, list2);
	int i1 = 0, i2 = 0;
	while (i1 < list1.size() && i2 < list2.size()) {
		if (list1[i1] < list2[i2]) {
			result.emplace_back(list1[i1]);
			++i1;
		} else {
			result.emplace_back(list2[i2]);
			++i2;
		}
	}

	if (i1 == list1.size()) {
		while (i2 < list2.size()) {
			result.emplace_back(list2[i2++]);
		}
	} else {
		while (i1 < list1.size()) {
			result.emplace_back(list1[i1++]);
		}
	}
	return result;
}
*/

vector<int> Solution::getAllElements(TreeNode* root1, TreeNode* root2) {
	vector<int> result;
	stack<TreeNode*> s1, s2;
	while (root1) {
		s1.emplace(root1);
		root1 = root1->left;
	}
	while (root2) {
		s2.emplace(root2);
		root2 = root2->left;
	}

	while (!s1.empty() && !s2.empty()) {
		if (s1.top()->val > s2.top()->val) {
			result.emplace_back(s2.top()->val);
			TreeNode* iter = s2.top()->right;
			s2.pop();
			while (iter) {
				s2.emplace(iter);
				iter = iter->left;
			}
		} else {
			result.emplace_back(s1.top()->val);
			TreeNode* iter = s1.top()->right;
			s1.pop();
			while (iter) {
				s1.emplace(iter);
				iter = iter->left;
			}
		}
	}
	stack<TreeNode*> st = s1.empty() ? move(s2) : move(s1);
	while (!st.empty()) {
		result.emplace_back(st.top()->val);
		TreeNode* iter = st.top()->right;
		st.pop();
		while (iter) {
			st.emplace(iter);
			iter = iter->left;
		}
	}

	return result;
}
