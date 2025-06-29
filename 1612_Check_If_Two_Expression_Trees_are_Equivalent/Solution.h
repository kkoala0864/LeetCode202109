#include <data_type.h>

struct Node {
	char val;
	Node *left;
	Node *right;
	Node() : val(' '), left(nullptr), right(nullptr) {}
	Node(char x) : val(x), left(nullptr), right(nullptr) {}
	Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	Solution() {
	}
	bool checkEquivalence(Node* root1, Node* root2);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
