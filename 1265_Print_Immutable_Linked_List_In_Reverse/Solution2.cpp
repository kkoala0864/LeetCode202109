#include <Solution.h>
#include <iostream>

void print(ImmutableListNode *node) {
	if (!node)
		return;
	print(node->getNext());
	node->printValue();
}

void Solution::printLinkedListInReverse2(ImmutableListNode *head) {
	print(head);
}
