#include <Solution.h>

int main(void) {
	int n = 2;
	int m = 3;
	// [1,2,3,4,5,6,7,8,9,10,11,12,13]
	ListNode *head = new ListNode(1);
	auto iter = head;
	for (int i = 2; i <= 13; ++i) {
		ListNode *node = new ListNode(i);
		iter->next = node;
		iter = iter->next;
	}
	iter = head;
	while (iter) {
		cout << iter->val << " ";
		iter = iter->next;
	}
	cout << endl;
	Solution *test = new Solution();
	ListNode *result = test->deleteNodes(head, n, m);
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	return 0;
}
