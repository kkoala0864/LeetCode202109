#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void dfs(Node*& ori, Node*& node, unordered_map<Node*, Node*>& map) {
	if (ori == nullptr) return;
	if (map.find(ori) != map.end()) {
		node = map[ori];
		return;
	}

	node = new Node(ori->val);
	map[ori] = node;
	dfs(ori->next, node->next, map);
	dfs(ori->random, node->random, map);
}

Node* Solution::copyRandomList2(Node* head) {
	unordered_map<Node*, Node*> map;
	Node* result = nullptr;
	dfs(head, result, map);
	return result;
}
