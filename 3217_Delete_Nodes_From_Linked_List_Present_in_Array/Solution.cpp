#include <Solution.h>

ListNode* Solution::modifiedList(vector<int>& nums, ListNode* head) {
	unordered_set<int> nus;
	for (const auto& v : nums) nus.emplace(v);

	ListNode* dummy = new ListNode(-1);
	dummy->next = head;

	auto prev = dummy;
	auto iter = head;

	while (iter) {
		if (nus.count(iter->val) == 0) {
			prev->next = iter;
			prev = iter;
		}
		iter = iter->next;
	}
	prev->next = nullptr;
	return dummy->next;
}
