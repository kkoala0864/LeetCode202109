#include <Solution.h>
#include <iostream>

Node *clone(Node *node, vector<Node *> &visited) {
	Node *cNode = new Node(node->val);
	visited[node->val] = cNode;
	for (const auto &iter : node->neighbors) {
		if (visited[iter->val] == nullptr) {
			cNode->neighbors.push_back(clone(iter, visited));
		} else {
			cNode->neighbors.push_back(visited[iter->val]);
		}
	}
	return cNode;
}

Node *Solution::cloneGraph2(Node *node) {
	if (!node)
		return node;
	vector<Node *> visited(101, nullptr);
	return clone(node, visited);
}
