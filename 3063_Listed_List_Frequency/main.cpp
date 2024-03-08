#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode* six = new ListNode(3, nullptr);
	ListNode* five = new ListNode(2, six);
	ListNode* four = new ListNode(1, five);
	ListNode* three = new ListNode(2, four);
	ListNode* two = new ListNode(1, three);
	ListNode* one = new ListNode(1, two);
	Solution* test = new Solution();
	auto result = test->frequenciesOfElements(one);
	ListNode* iter = result;
	while (iter) {
		cout << iter->val << " ";
		iter = iter->next;
	}
	cout << endl;
	return 0;
}

