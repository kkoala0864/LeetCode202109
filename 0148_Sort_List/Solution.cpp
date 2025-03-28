#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

ListNode *merge(ListNode *lhs, ListNode *rhs) {
	if (!lhs)
		return rhs;
	if (!rhs)
		return lhs;

	ListNode *head = nullptr;
	if (lhs->val < rhs->val) {
		head = lhs;
		lhs = lhs->next;
	} else {
		head = rhs;
		rhs = rhs->next;
	}
	ListNode *iter = head;

	while (lhs && rhs) {
		if (lhs->val < rhs->val) {
			iter->next = lhs;
			lhs = lhs->next;
		} else {
			iter->next = rhs;
			rhs = rhs->next;
		}
		iter = iter->next;
	}
	if (lhs)
		iter->next = lhs;
	else
		iter->next = rhs;
	return head;
}

ListNode *divide(ListNode *node, int size) {
	if (size == 1) {
		node->next = nullptr;
		return node;
	}

	int cnt = size & 1 ? (size / 2) + 1 : (size / 2);
	ListNode *iter = node;
	int dec = cnt;
	while (dec > 0) {
		iter = iter->next;
		--dec;
	}
	return merge(divide(node, cnt), divide(iter, size - cnt));
}

ListNode *Solution::sortList(ListNode *head) {
	ListNode *iter = head;
	int size = 0;
	if (!iter || !iter->next)
		return head;
	while (iter) {
		++size;
		iter = iter->next;
	}

	return divide(head, size);
}
/*
ListNode* Solution::sortList(ListNode* head) {
        vector<ListNode*> vec;
        while (head) {
                vec.emplace_back(head);
                head = head->next;
        }
        auto cmp = [] (ListNode* lhs, ListNode* rhs) { return lhs->val < rhs->val; };
        sort(vec.begin(), vec.end(), cmp);
        for (int i = 0 ; i < vec.size()-1 ; ++i) {
                vec[i]->next = vec[i+1];
        }
        vec.back()->next = nullptr;
        return vec[0];
}*/
