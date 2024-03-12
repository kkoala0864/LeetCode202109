#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

ListNode* Solution::removeZeroSumSublists(ListNode* head) {
	unordered_map<int, ListNode*> m;

	int sum = 0;
	ListNode* dummy = new ListNode(0, head);

	ListNode* iter = dummy;
	while (iter) {
		sum += iter->val;
		if (m.count(sum)) {
			ListNode* removeIter = m[sum]->next;
			int tmpSum = sum;
			while (removeIter && removeIter != iter) {
				tmpSum += removeIter->val;
				m.erase(tmpSum);
				removeIter = removeIter->next;
			}
			m[sum]->next = iter->next;
		} else {
			m[sum] = iter;
		}
		iter = iter->next;
	}
	return dummy->next;
}
