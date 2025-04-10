class Node {
public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node()
	    : val(0), left(nullptr), right(nullptr), next(nullptr) {
	}

	Node(int _val)
	    : val(_val), left(nullptr), right(nullptr), next(nullptr) {
	}

	Node(int _val, Node *_left, Node *_right, Node *_next)
	    : val(_val), left(_left), right(_right), next(_next) {
	}
};

class Solution {
public:
	Solution() {
	}
	Node *connect(Node *root);
	Node *connect2(Node *root);
	Node *connect3(Node *root);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
