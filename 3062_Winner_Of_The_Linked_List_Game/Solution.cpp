#include <Solution.h>
#include <iostream>

string Solution::gameResult(ListNode *head) {
	ListNode *eIter = head;
	ListNode *oIter = head->next;

	int eVal = 0, oVal = 0;
	while (eIter) {
		eIter->val > oIter->val ? ++eVal : ++oVal;
		eIter = oIter->next;
		if (eIter)
			oIter = eIter->next;
	}
	return eVal == oVal ? "Tie" : eVal > oVal ? "Even"
	                                          : "Odd";
}
