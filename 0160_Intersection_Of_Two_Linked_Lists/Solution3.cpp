#include <Solution.h>
#include <iostream>

ListNode* Solution::getIntersectionNode3(ListNode *headA, ListNode *headB) {
	int aSize = 0, bSize = 0;
	ListNode* ia = headA, *ib = headB;
	while (ia || ib) {
		if (ia) {
			++aSize;
			ia = ia->next;
		}
		if (ib) {
			++bSize;
			ib = ib->next;
		}
	}

	ListNode* l = aSize > bSize ? headA : headB;
	ListNode* s = l == headA ? headB : headA;
	int sDiff = abs(aSize - bSize);
	while (sDiff-- > 0) l = l->next;

	while (l) {
		if (l == s) return l;
		l = l->next;
		s = s->next;
	}
	return nullptr;
}
