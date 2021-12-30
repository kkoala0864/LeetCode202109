#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
	if (!l1) return l2;
	if (!l2) return l1;

	ListNode* head = nullptr, *iter = nullptr;
	if (l1->val < l2->val) {
		head = l1;
		l1 = l1->next;
	} else {
		head = l2;
		l2 = l2->next;
	}
	iter = head;

	while (l1 && l2) {
		if (l1->val < l2->val) {
			iter->next = l1;
			while (l1->next && l1->next->val < l2->val) {
				l1 = l1->next;
			}
			iter = l1;
			l1 = l1->next;
		} else if (l2->val < l1->val) {
			iter->next = l2;
			while (l2->next && l2->next->val < l1->val) {
				l2 = l2->next;
			}
			iter = l2;
			l2 = l2->next;
		} else {
			iter->next = l1;
			while (l1->next && l1->next->val == l1->val) {
				l1 = l1->next;
			}
			iter = l1;
			l1 = l1->next;
			iter->next = l2;
			while (l2->next && l2->next->val == l2->val) {
				l2 = l2->next;
			}
			iter = l2;
			l2 = l2->next;
		}
	}

	if (l1) iter->next = l1;
	else iter->next = l2;

	return head;
}


ListNode* Solution::mergeKLists2(vector<ListNode*>& lists) {
	queue<ListNode*> que;
	for (const auto& iter : lists) {
		que.emplace(iter);
	}

	while (que.size() > 1) {
		ListNode* l1 = que.front(); que.pop();
		ListNode* l2 = que.front(); que.pop();
		ListNode* merge = mergeTwoLists2(l1, l2);
		que.emplace(merge);
	}
	return que.front();
}
