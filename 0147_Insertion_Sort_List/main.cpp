#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode *head = new ListNode(4);
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(1);
	ListNode *node3 = new ListNode(3);
	head->next = node1;
	node1->next = node2;
	node2->next = node3;

	Solution *test = new Solution();
	auto result = test->insertionSortList(head);
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	return 0;
}
