#include <Solution.h>
#include <iostream>

ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
	int aSize = 0, bSize = 0;

	ListNode *iter = headA;
	while (iter) {
		++aSize;
		iter = iter->next;
	}
	iter = headB;
	while (iter) {
		++bSize;
		iter = iter->next;
	}

	ListNode *moreIter = nullptr;
	ListNode *lessIter = nullptr;
	int diff = 0;
	if (aSize > bSize) {
		moreIter = headA;
		lessIter = headB;
		diff = aSize - bSize;
	} else {
		moreIter = headB;
		lessIter = headA;
		diff = bSize - aSize;
	}

	while (diff--)
		moreIter = moreIter->next;

	while (moreIter) {
		if (moreIter == lessIter)
			return moreIter;
		moreIter = moreIter->next;
		lessIter = lessIter->next;
	}
	return nullptr;
}
