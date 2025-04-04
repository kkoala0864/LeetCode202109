class Node {
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution {
public:
	Solution() {
	}
	Node *copyRandomList(Node *head);
	Node *copyRandomList2(Node *head);
	Node *copyRandomList3(Node *head);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
