#include <vector>

using std::vector;

class Node {
public:
	int val;
	vector<Node *> children;

	Node() {
	}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node *> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	Solution() {
	}
	Node *cloneTree(Node *root);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
