#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode *head = new ListNode(1);
	Solution *test = new Solution();
	cout << test->hasCycle(head) << endl;
	cout << test->hasCycle2(head) << endl;
	cout << test->hasCycle3(head) << endl;
	cout << test->hasCycle4(head) << endl;
	return 0;
}
