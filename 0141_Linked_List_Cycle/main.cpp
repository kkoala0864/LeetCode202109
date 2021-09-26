#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	ListNode* head = new ListNode(1);
    Solution* test = new Solution();
    cout << test->hasCycle(head) << endl;
    return 0;
}

