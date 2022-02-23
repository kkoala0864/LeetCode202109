#include <Solution.h>
#include <iostream>

Node* Clone(Node* node, vector<Node*>& map) {
	if (map[node->val]) return map[node->val];

	Node* copy = new Node(node->val);
	map[node->val] = copy;
	for (const auto& iter : node->neighbors) {
		copy->neighbors.emplace_back(Clone(iter, map));
	}
	return copy;
}

Node* Solution::cloneGraph3(Node* node) {
	if (!node) return node;
	vector<Node*> map(101, nullptr);
	return Clone(node,map);
}
