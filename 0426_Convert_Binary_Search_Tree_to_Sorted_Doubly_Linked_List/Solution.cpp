#include <Solution.h>

void dfs(Node* node, Node*& start, Node*& tail) {
	if (!node) return;

	dfs(node->left, start, tail);
	if (tail != nullptr) {
		node->left = tail;
		tail->right = node;
	}
	tail = node;
	if (!start) start = node;
	dfs(node->right, start, tail);
}

Node* Solution::treeToDoublyList(Node* root) {
	if (!root) return nullptr;
	Node* tail = nullptr;
	Node* start = nullptr;
	dfs(root, start, tail);
	start->left = tail;
	tail->right = start;
	return start;
}
