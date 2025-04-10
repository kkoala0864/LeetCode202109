#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	//[3,5,6]
	//1
	Node *head = new Node(3);
	Node *node1 = new Node(5);
	Node *node2 = new Node(1);
	head->next = node1;
	node1->next = node2;
	node2->next = head;
	int k = 6;
	Solution *test = new Solution();
	Node *result = test->insert(head, k);
	for (int i = 0; i < 4; i++) {
		cout << result->val << " ";
		result = result->next;
	}
	return 0;
}
