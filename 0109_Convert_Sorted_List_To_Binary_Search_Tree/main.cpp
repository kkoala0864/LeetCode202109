#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void dfs(TreeNode* node) {
	if (!node) return;
	dfs(node->left);
	cout << node->val << " ";
	dfs(node->right);
}

int main(void) {
	vector<int> input = {-10,-3,0,5,9};
	ListNode* head = nullptr, *iter = nullptr;
	for (int i = 0 ; i < input.size() ; ++i) {
		if (head) {
			iter->next = new ListNode(input[i]);
			iter = iter->next;
		} else {
			head = new ListNode(input[i]);
			iter = head;
		}
	}
	Solution* test = new Solution();
	TreeNode* ret = test->sortedListToBST2(head);
	dfs(ret);
	return 0;
}

