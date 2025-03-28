#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5, 3, 1, 2, 5, 1, 2};
	ListNode *head = new ListNode(input[0]);
	ListNode *cur = head;
	for (int i = 1; i < input.size(); ++i) {
		cur->next = new ListNode(input[i]);
		cur = cur->next;
	}
	Solution *test = new Solution();
	auto result = test->nodesBetweenCriticalPoints(head);
	cout << result[0] << " : " << result[1] << endl;
	return 0;
}
