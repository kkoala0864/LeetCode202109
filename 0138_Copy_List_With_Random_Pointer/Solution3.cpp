#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void dfs(Node *ori, Node *&copy, unordered_map<Node *, Node *> &uMap) {
	if (!ori)
		return;

	copy = new Node(ori->val);
	uMap[ori] = copy;
	dfs(ori->next, copy->next, uMap);
	copy->random = uMap[ori->random];
}

Node *Solution::copyRandomList3(Node *head) {
	if (!head)
		return head;
	unordered_map<Node *, Node *> uMap;
	Node *result = nullptr;
	dfs(head, result, uMap);
	return result;
}
