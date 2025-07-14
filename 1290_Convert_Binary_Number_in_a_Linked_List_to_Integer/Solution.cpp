#include <Solution.h>

int Solution::getDecimalValue(ListNode* head) {
	int v = 0;
	while (head) {
		v <<= 1;
		v += head->val;
		head = head->next;
	}

	return v;
}
