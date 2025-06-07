#include <Solution.h>

int main(void) {
	//2,1,5
	ListNode *root = new ListNode(2);
	root->next = new ListNode(1);
	root->next->next = new ListNode(5);

	Solution *test = new Solution();
	vector<int> result = test->nextLargerNodes(root);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
