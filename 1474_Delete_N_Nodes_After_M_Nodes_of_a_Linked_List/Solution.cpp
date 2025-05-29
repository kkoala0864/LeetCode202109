#include <Solution.h>

ListNode* Solution::deleteNodes(ListNode* head, int m, int n) {
	ListNode* dummy = new ListNode();
	dummy->next = head;
	auto iter = head;
	auto prev = dummy;

	int cnt = 0;
	bool isM = true;
	while (iter) {
		if (isM) {
			prev = iter;
			iter = iter->next;
			++cnt;
			if (cnt == m) {
				cnt = 0;
				isM = !isM;
			}
		} else {
			prev->next = iter->next;
			iter = iter->next;
			++cnt;
			if (cnt == n) {
				cnt = 0;
				isM = !isM;
			}
		}
	}
	return dummy->next;
}
