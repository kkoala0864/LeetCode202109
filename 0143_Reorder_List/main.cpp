#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode* five = new ListNode(5);
	ListNode* four = new ListNode(4);
	ListNode* three = new ListNode(3, four);
	ListNode* two = new ListNode(2, three);
	ListNode* one = new ListNode(1, two);
	Solution* test = new Solution();
	test->reorderList2(one);
	ListNode* iter = one;
	while (iter) {
		cout << iter->val << endl;
		iter = iter->next;
	}
	return 0;
}

