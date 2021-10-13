#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode* two2 = new ListNode(2);
	ListNode* five = new ListNode(5, two2);
	ListNode* two1 = new ListNode(2, five);
	ListNode* three = new ListNode(3, two1);
	ListNode* four = new ListNode(4, three);
	ListNode* one = new ListNode(1, four);
	Solution* test = new Solution();
	ListNode* result = test->partition(one, 3);
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	return 0;
}

