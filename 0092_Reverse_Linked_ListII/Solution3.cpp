#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
// how long is this list ?
// what's the range of the value in this list?
// what's the l and r range ?
// 1 2 3 4 5  2, 4
ListNode *Solution::reverseBetween3(ListNode *head, int left, int right) {
	ListNode *iter = head;
	ListNode *li = nullptr;
	ListNode *lp = nullptr;
	ListNode *rs = nullptr;
	ListNode *next = nullptr;

	for (int i = 1; i < left; ++i) {
		li = iter;
		iter = iter->next;
	}
	lp = li;
	rs = iter;
	for (int i = left; i <= right; ++i) {
		next = iter->next;
		iter->next = li;
		li = iter;
		iter = next;
	}
	rs->next = iter;
	if (lp) {
		lp->next = li;
	} else {
		head = li;
	}
	return head;
}
