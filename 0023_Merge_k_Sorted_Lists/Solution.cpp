#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	ListNode *iter1 = l1;
	ListNode *iter2 = l2;
	ListNode *head = nullptr;
	if (iter1->val <= iter2->val) {
		head = iter1;
		iter1 = iter1->next;
	} else {
		head = iter2;
		iter2 = iter2->next;
	}
	ListNode *resultIter = head;
	while (iter1 && iter2) {
		if (iter1->val < iter2->val) {
			resultIter->next = iter1;
			while (iter1->next != nullptr && iter1->next->val < iter2->val) {
				iter1 = iter1->next;
			}
			resultIter = iter1;
			iter1 = iter1->next;
		} else if (iter2->val < iter1->val) {
			resultIter->next = iter2;
			while (iter2->next != nullptr && iter2->next->val < iter1->val) {
				iter2 = iter2->next;
			}
			resultIter = iter2;
			iter2 = iter2->next;
		} else {
			resultIter->next = iter2;
			while (iter2->next != nullptr && iter2->next->val == iter2->val) {
				iter2 = iter2->next;
			}
			resultIter = iter2;
			iter2 = iter2->next;
			resultIter->next = iter1;
			while (iter1->next != nullptr && iter1->next->val == iter1->val) {
				iter1 = iter1->next;
			}
			resultIter = iter1;
			iter1 = iter1->next;
		}
	}

	if (iter1) {
		resultIter->next = iter1;
	} else {
		resultIter->next = iter2;
	}
	return head;
}

ListNode *Solution::mergeKLists(vector<ListNode *> &lists) {
	if (lists.empty())
		return nullptr;
	queue<ListNode *> que;
	for (const auto iter : lists) {
		que.emplace(iter);
	}

	while (que.size() > 1) {
		ListNode *list1 = que.front();
		que.pop();
		ListNode *list2 = que.front();
		que.pop();
		ListNode *tmp = mergeTwoLists(list1, list2);
		que.emplace(tmp);
	}
	return que.front();
}
