#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
/*
void dfs(Node* node, vector<Node*>& st) {
        if (!node) return;
        dfs(node->left, st);
        node->left = st.empty() ? nullptr : st.back();
        st.emplace_back(node);
        dfs(node->right, st);
}

Node* Solution::treeToDoublyList(Node* root) {
        if (!root) return root;
        vector<Node*> st;
        dfs(root, st);
        for (int i = 0 ; i < st.size()-1 ; ++i) {
                st[i]->right = st[i+1];
        }
        if (!st.empty()) {
                st[0]->left = st.back();
                st.back()->right = st[0];
        }
        return st[0];
}
*/
Node *head = nullptr;
Node *tail = nullptr;

void dfs(Node *node) {
	if (!node)
		return;
	dfs(node->left);
	if (!head)
		head = node;
	else {
		node->left = tail;
		tail->right = node;
	}
	tail = node;
	dfs(node->right);
}

Node *Solution::treeToDoublyList(Node *root) {
	if (!root)
		return root;
	dfs(root);
	head->left = tail;
	tail->right = head;
	return head;
}
