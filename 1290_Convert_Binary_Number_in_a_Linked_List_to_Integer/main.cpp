#include <Solution.h>

int main(void) {
	//[1,0,1]
	ListNode *head = new ListNode(1);
	head->next = new ListNode(0);
	head->next->next = new ListNode(1);

	Solution *test = new Solution();
	cout << test->getDecimalValue(head) << endl;
	return 0;
}
