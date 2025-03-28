#include <Solution.h>
#include <iostream>

ListNode *Solution::getIntersectionNode2(ListNode *headA, ListNode *headB) {
	int aSize = 0, bSize = 0;
	ListNode *ai = headA, *bi = headB;
	while (ai) {
		++aSize;
		ai = ai->next;
	}
	while (bi) {
		++bSize;
		bi = bi->next;
	}
	ListNode *li = aSize > bSize ? headA : headB;
	ListNode *si = li == headA ? headB : headA;
	int diff = abs(aSize - bSize);
	while (diff-- > 0)
		li = li->next;
	while (li && si) {
		if (li == si)
			return li;
		li = li->next;
		si = si->next;
	}
	return nullptr;
}
