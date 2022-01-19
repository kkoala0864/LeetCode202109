#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode* one = new ListNode(-4);
	ListNode* two = new ListNode(0);
	two->next = one;
	ListNode* three = new ListNode(2);
	three->next = two;
	ListNode* four = new ListNode(3);
	four->next = three;
	one->next = three;
	Solution* test = new Solution();
	ListNode* ret = test->detectCycle(four);
	cout << ret->val << endl;
    return 0;
}

