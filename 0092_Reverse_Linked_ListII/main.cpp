#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode *five = new ListNode(5);
	ListNode *four = new ListNode(4, five);
	ListNode *three = new ListNode(3, four);
	ListNode *two = new ListNode(2, three);
	ListNode *one = new ListNode(1, two);
	Solution *test = new Solution();
	ListNode *result = test->reverseBetween3(one, 2, 4);
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	return 0;
}
