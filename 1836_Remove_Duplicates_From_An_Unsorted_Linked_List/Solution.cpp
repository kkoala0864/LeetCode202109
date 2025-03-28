#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using std::unordered_map;
using std::unordered_set;

ListNode *Solution::deleteDuplicatesUnsorted(ListNode *head) {
	unordered_map<int, int> m;
	unordered_set<ListNode *> remove_set;
	ListNode *dummy = new ListNode(-1, head);

	ListNode *iter = head;
	while (iter) {
		++m[iter->val];
		iter = iter->next;
	}
	iter = head;
	ListNode *prev = dummy;

	while (iter) {
		if (m[iter->val] > 1) {
			prev->next = iter->next;
		} else {
			prev = iter;
		}
		iter = iter->next;
	}
	return dummy->next;
}
