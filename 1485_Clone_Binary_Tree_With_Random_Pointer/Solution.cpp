#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

NodeCopy* dfs(Node* node, unordered_map<Node*, NodeCopy*>& uMap) {
	if (!node) return nullptr;
	if (uMap.count(node)) return uMap[node];

	NodeCopy* nc = new NodeCopy();
	uMap[node] = nc;
	nc->val = node->val;

	nc->random = dfs(node->random, uMap);
	nc->left = dfs(node->left, uMap);
	nc->right = dfs(node->right, uMap);
	return nc;
}


NodeCopy* Solution::copyRandomBinaryTree(Node* root) {
	unordered_map<Node*, NodeCopy*> uMap;
	return dfs(root, uMap);
}
