class ImmutableListNode {
public:
	void printValue();            // print the value of the node.
	ImmutableListNode *getNext(); // return the next node.
};

class Solution {
public:
	Solution() {
	}
	void printLinkedListInReverse(ImmutableListNode *head);
	void printLinkedListInReverse2(ImmutableListNode *head);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
