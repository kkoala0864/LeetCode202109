#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode *five = new ListNode(-2, nullptr);
	ListNode *four = new ListNode(-3, five);
	ListNode *three = new ListNode(3, four);
	ListNode *two = new ListNode(2, three);
	ListNode *one = new ListNode(1, two);
	Solution *test = new Solution();
	auto result = test->removeZeroSumSublists(one);
	auto iter = result;
	while (iter) {
		cout << iter->val << " ";
		iter = iter->next;
	}
	cout << endl;
	return 0;
}
