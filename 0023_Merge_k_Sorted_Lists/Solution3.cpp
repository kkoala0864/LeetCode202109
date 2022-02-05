#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
	if (!l1) return l2;
	if (!l2) return l1;

	ListNode* result = nullptr, iter = nullptr;
	ListNode* iter1 = l1, *iter2 = l2;

	while (iter1 && iter2) {
		if (iter1->val <= iter2->val) {
			if (result) {
				iter->next = iter1;
				iter = iter->next;
			} else {
				result = iter1;
				iter = result;
			}
			iter1 = iter1->next;
		} else {
			if (result) {
				iter->next = iter2;
				iter = iter->next;
			} else {
				result = iter2;
				iter = result;
			}
			iter2 = iter2->next;
		}
	}

	ListNode* rest = iter1 ? iter1 : iter2;
	while (rest) {
		iter->next = rest;
		rest = rest->next;
		iter = iter->next;
	}
	return result;
}

ListNode* Solution::mergeKLists3(vector<ListNode*>& lists) {
	queue<ListNode*> que;
	for (const auto& iter : lists) if (iter) que.emplace(iter);

	while (que.size() > 1) {
		ListNode* one = que.front();
		que.pop();
		ListNode* two = que.front();
		que.pop();
		que.emplace(mergeTwo(one, two));
	}
	return que.empty() ? nullptr : que.front();
}

