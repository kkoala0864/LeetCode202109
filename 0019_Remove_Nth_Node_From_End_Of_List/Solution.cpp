#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
// Clarify
// 1. does this linked-list have loop ?
// 2. if head is nullptr, what should return ? or i can assume this head would always has node
// 3. how many number of node is this linked list maximum ?

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
	if (head == nullptr) return head;
	vector<ListNode*> location(30, nullptr);

	int index = 0;
	location[index++] = head;
	ListNode* iter = head->next;
	while (iter != nullptr) {
		location[index++] = iter;
		iter = iter->next;
	}

	int size = index;
	int removeIdx = size - 1 - n + 1;
	int front = removeIdx - 1;
	ListNode* frontPtr = nullptr;
	int backend = removeIdx + 1;
	ListNode* backendPtr = nullptr;

	if (backend >= index) backendPtr = nullptr;
	else backendPtr = location[backend];

	if (front < 0) head = backendPtr;
	else {
		frontPtr = location[front];
		frontPtr->next = backendPtr;
	}
	return head;
}
