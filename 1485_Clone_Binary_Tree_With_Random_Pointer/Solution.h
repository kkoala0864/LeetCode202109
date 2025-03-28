struct Node
{
	int val;
	Node *left;
	Node *right;
	Node *random;
	Node()
	    : val(0), left(nullptr), right(nullptr), random(nullptr) {
	}
	Node(int x)
	    : val(x), left(nullptr), right(nullptr), random(nullptr) {
	}
	Node(int x, Node *left, Node *right, Node *random)
	    : val(x), left(left), right(right), random(random) {
	}
};

struct NodeCopy
{
	int val;
	NodeCopy *left;
	NodeCopy *right;
	NodeCopy *random;
	NodeCopy()
	    : val(0), left(nullptr), right(nullptr), random(nullptr) {
	}
	NodeCopy(int x)
	    : val(x), left(nullptr), right(nullptr), random(nullptr) {
	}
	NodeCopy(int x, NodeCopy *left, NodeCopy *right, NodeCopy *random)
	    : val(x), left(left), right(right), random(random) {
	}
};

class Solution {
public:
	Solution() {
	}
	NodeCopy *copyRandomBinaryTree(Node *root);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
