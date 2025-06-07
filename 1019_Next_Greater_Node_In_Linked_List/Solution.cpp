#include <Solution.h>

vector<int> Solution::nextLargerNodes(ListNode* head) {
	vector<int> result;
	stack<pair<int, int>> st;
	auto iter = head;
	while (iter) {
		result.emplace_back(0);
		while (!st.empty() && st.top().second < iter->val) {
			result[st.top().first] = iter->val;
			st.pop();
		}
		st.emplace(pair<int, int>(result.size() - 1, iter->val));
		iter = iter->next;
	}
	return result;
}
