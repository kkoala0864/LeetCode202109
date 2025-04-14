#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	// [7,2,4,3]
	// [5,6,4]
	ListNode *l1 = new ListNode(7);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	l1->next->next->next = new ListNode(3);
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	Solution *test = new Solution();
	auto result = test->addTwoNumbers(l1, l2);
	while (result != nullptr) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	return 0;
}
