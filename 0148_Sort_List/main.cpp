#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode *three = new ListNode(3);
	ListNode *one = new ListNode(1, three);
	ListNode *two = new ListNode(2, one);
	// ListNode* four = new ListNode(4, two);
	// ListNode* five = new ListNode(5, four);
	ListNode *head = two;
	Solution *test = new Solution();
	ListNode *ret = test->sortList(head);
	while (ret) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	cout << endl;

	return 0;
}
