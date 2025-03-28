#include <Solution.h>
#include <iostream>

Node *Clone(vector<Node *> &uMap, Node *node) {
	if (uMap[node->val])
		return uMap[node->val];
	uMap[node->val] = new Node(node->val);
	vector<Node *> neighbors;
	for (const auto &iter : node->neighbors)
		neighbors.emplace_back(Clone(uMap, iter));
	uMap[node->val]->neighbors = neighbors;
	return uMap[node->val];
}

Node *Solution::cloneGraph(Node *node) {
	vector<Node *> uMap(200, nullptr);
	return Clone(uMap, node);
}
