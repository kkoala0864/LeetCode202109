#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

ListNode* Solution::modifiedList(vector<int>& nums, ListNode* head) {
	unordered_set<int> us;

	for (const auto& v : nums) us.emplace(v);

	ListNode* dummy = new ListNode(-1, head);

	ListNode* iter = dummy;
	while (iter) {
		if (iter->next && us.count(iter->next->val)) {
			iter->next = iter->next->next;
		} else {
			iter = iter->next;
		}
	}
	return dummy->next;

}
