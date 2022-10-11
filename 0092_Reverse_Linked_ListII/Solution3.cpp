#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
// how long is this list ?
// what's the range of the value in this list?
// what's the l and r range ?
// 1 2 3 4 5  2, 4
ListNode* Solution::reverseBetween3(ListNode* head, int left, int right) {
	if (left == right || !head) return head;
	int cnt = 1;

	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* prev = nullptr;
	ListNode* next = nullptr;
	ListNode* appendPrev = dummy;
	ListNode* iter = head;

	while (iter) {
		if (left <= cnt && cnt <= right) {
			next = iter->next;
			iter->next = prev;
			prev = iter;
			iter = next;
			if (cnt == right) {
				appendPrev->next->next = iter;
				appendPrev->next = prev;
			}
		} else {
			appendPrev = iter;
			iter = iter->next;
		}
		++cnt;
	}
	return dummy->next;
}
