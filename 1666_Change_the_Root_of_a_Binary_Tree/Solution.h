#include <data_type.h>

class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node* parent;
};

class Solution {
public:
	Solution() {
	}
	Node* flipBinaryTree(Node* root, Node * leaf);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
