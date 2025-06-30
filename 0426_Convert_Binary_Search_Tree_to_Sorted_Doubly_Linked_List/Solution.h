#include <data_type.h>

class Node {
	public:
		int val;
		Node* left;
		Node* right;

		Node() {}

		Node(int _val) {
			val = _val;
			left = NULL;
			right = NULL;
		}

		Node(int _val, Node* _left, Node* _right) {
			val = _val;
			left = _left;
			right = _right;
		}
};

class Solution {
public:
	Solution() {
	}
	Node* treeToDoublyList(Node* root);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
