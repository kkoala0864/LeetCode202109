#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode* five = new ListNode(5, nullptr);
	ListNode* four = new ListNode(4, five);
	ListNode* three = new ListNode(3, four);
	ListNode* two = new ListNode(2, three);
	ListNode* one = new ListNode(1, two);
    Solution* test = new Solution();
    ListNode* ret = test->reverseList2(one);
    ListNode* iter = ret;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
	cout << endl;
    return 0;
}

