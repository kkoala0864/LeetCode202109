#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

Node *Solution::connect(Node *root) {
	if ((!root) || (!root->left && !root->right))
		return root;

	root->left->next = root->right;
	Node *leftMostRight = root->left;
	Node *rightMostLeft = root->right;
	while (leftMostRight->right) {
		leftMostRight = leftMostRight->right;
		rightMostLeft = rightMostLeft->left;
		leftMostRight->next = rightMostLeft;
	}

	connect(root->left);
	connect(root->right);
	return root;
}

/*
Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> cur, next;

        cur.emplace(root);

        while (!cur.empty()) {
                Node* node = cur.front();
                cur.pop();

                if (!cur.empty()) node->next = cur.front();

                if (node->left) next.emplace(node->left);
                if (node->right) next.emplace(node->right);

                if (cur.empty()) {
                        cur = move(next);
                }
        }
        return root;
}
*/
