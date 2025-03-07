#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

ListNode* Solution::insertionSortList(ListNode* head) {
	ListNode* ret = new ListNode(-1);
	auto iter = head;
	ListNode* prev = nullptr, *cur = nullptr, *next = nullptr;

	while (iter) {
		prev = ret;
		cur = ret->next;
		while (cur) {
			if (cur->val >= iter->val) break;
			prev = cur;
			cur = cur->next;
		}
		next = iter->next;
		prev->next = iter;
		iter->next = cur;
		iter = next;
	}
	return ret->next;
}
