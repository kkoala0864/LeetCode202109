#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

ListNode* Solution::frequenciesOfElements(ListNode* head) {
	unordered_map<int, ListNode*> m;
	ListNode* dummy = new ListNode(0, head);
	ListNode* iter = dummy;

	while (iter && iter->next) {
		if (m.count(iter->next->val)) {
			++m[iter->next->val]->val;
			iter->next = iter->next->next;
		} else {
			m[iter->next->val] = iter->next;
			iter->next->val = 1;
			iter = iter->next;
		}
	}
	return dummy->next;
}
