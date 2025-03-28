#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;
using std::swap;

Node *Solution::treeToDoublyList2(Node *root) {
	if (!root)
		return nullptr;
	stack<Node *> st;
	Node *front = nullptr, *frontIter = nullptr;
	Node *iter = root;
	while (iter) {
		st.emplace(iter);
		iter = iter->left;
	}

	while (!st.empty()) {
		iter = st.top();
		st.pop();
		if (!front) {
			front = iter;
			frontIter = iter;
		} else {
			frontIter->left = iter;
			frontIter = frontIter->left;
		}

		iter = iter->right;
		while (iter) {
			st.emplace(iter);
			iter = iter->left;
		}
	}
	frontIter->left = nullptr;

	frontIter = front;
	while (frontIter->left) {
		frontIter->left->right = frontIter;
		swap(frontIter->left, frontIter->right);
		frontIter = frontIter->right;
	}
	frontIter->left = front;
	swap(frontIter->left, frontIter->right);
	front->left = frontIter;
	return front;
}
