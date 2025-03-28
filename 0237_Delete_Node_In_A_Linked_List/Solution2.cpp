#include <Solution.h>
#include <iostream>

using std::swap;

void Solution::deleteNode2(ListNode *node) {
	swap(node->val, node->next->val);
	node->next = node->next->next;
}
