#include <Solution.h>
#include <iostream>

Node *clone(Node *node) {
	if (!node)
		return nullptr;
	vector<Node *> list;
	for (const auto &iter : node->children) {
		list.emplace_back(clone(iter));
	}
	return new Node(node->val, list);
}

Node *Solution::cloneTree(Node *root) {
	return clone(root);
}
