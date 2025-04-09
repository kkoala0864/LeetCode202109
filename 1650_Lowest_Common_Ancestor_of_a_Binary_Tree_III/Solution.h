#include <data_type.h>

using namespace std;

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
	Node* lowestCommonAncestor(Node* p, Node * q);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
