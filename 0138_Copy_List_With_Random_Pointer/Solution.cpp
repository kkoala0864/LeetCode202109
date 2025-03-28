#include <Solution.h>
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using std::unordered_map;

Node *Copy(unordered_map<Node *, Node *> &uMap, Node *iter) {
	if (!iter)
		return iter;

	if (uMap.find(iter) == uMap.end()) {
		Node *newIter = new Node(iter->val);
		uMap[iter] = newIter;
		newIter->next = Copy(uMap, iter->next);
		newIter->random = Copy(uMap, iter->random);
		return newIter;
	} else {
		return uMap[iter];
	}
}

Node *Solution::copyRandomList(Node *head) {
	unordered_map<Node *, Node *> uMap;
	return Copy(uMap, head);
}
