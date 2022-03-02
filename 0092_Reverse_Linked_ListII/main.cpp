#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode* five = new ListNode(5);
	ListNode* three = new ListNode(3, five);
	Solution* test = new Solution();
	ListNode* result = test->reverseBetween2(three, 1, 2);
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	return 0;
}

