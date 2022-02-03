#include <Solution.h>
#include <iostream>
using std::swap;

ListNode* Solution::oddEvenList3(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* evenhead = head->next;
	ListNode* curIter = head, *nextIter = evenhead;

	ListNode* iter = evenhead->next;
	bool isOdd = true;
	while (iter) {
		curIter->next = iter;
		curIter = curIter->next;
		iter = iter->next;
		swap(curIter, nextIter);
		isOdd = !isOdd;
	}
	curIter->next = nullptr;
	if (!isOdd) swap(curIter, nextIter);

	curIter->next = evenhead;
	return head;
}
