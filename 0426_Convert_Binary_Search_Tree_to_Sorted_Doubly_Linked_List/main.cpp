#include <Solution.h>

int main(void) {
	//[4,2,5,1,3]
	Node *head = new Node(4);
	head->left = new Node(2);
	head->right = new Node(5);
	head->left->left = new Node(1);
	head->left->right = new Node(3);
	Solution *test = new Solution();
	auto result = test->treeToDoublyList(head);
	auto iter = result->right;
	while (iter != result) {
		std::cout << iter->val << " ";
		iter = iter->right;
	}
	cout << endl;
	iter = result->left;
	while (iter != result) {
		std::cout << iter->val << " ";
		iter = iter->left;
	}
	cout << endl;
	return 0;
}
