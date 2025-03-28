#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode *onefour = new ListNode(4);
	ListNode *onetwo = new ListNode(2, onefour);
	ListNode *oneone = new ListNode(1, onetwo);
	ListNode *twofour = new ListNode(4);
	ListNode *twothree = new ListNode(3, twofour);
	ListNode *twoone = new ListNode(1, twothree);
	Solution *test = new Solution();
	ListNode *result = test->mergeTwoLists3(oneone, twoone);
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	return 0;
}
