#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::min;
using std::max;
using std::cout;
using std::endl;

vector<int> Solution::nodesBetweenCriticalPoints(ListNode* head) {
	int minIdx = INT_MAX;
	int lastIdx = INT_MAX;
	int cur = 0;
	ListNode* pre = nullptr;
	ListNode* iter = head;
	ListNode* next = head->next;
	vector<int> result = {INT_MAX, INT_MIN};
	while (iter && next) {
		if (pre != nullptr) {
			if ((iter->val > pre->val && iter->val > next->val) ||
				(iter->val < pre->val && iter->val < next->val)) {
				if (minIdx != INT_MAX) {
					result[0] = min(result[0], cur - lastIdx);
					result[1] = max(result[1], cur - minIdx);
				}
				minIdx = min(minIdx, cur);
				lastIdx = cur;
			}
		}
		++cur;
		pre = iter;
		iter = iter->next;
		next = iter->next;
	}
	return result[0] == INT_MAX ? vector<int>({-1, -1}) : result;

}
