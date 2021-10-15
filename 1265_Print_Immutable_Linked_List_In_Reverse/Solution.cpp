#include <Solution.h>
#include <iostream>

void print(ImmutableListNode* head) {
	if (!head) return;
	print(head->getNext());
	head->printValue();
}

void Solution::printLinkedListInReverse(ImmutableListNode* head) {
	print(head);
}
