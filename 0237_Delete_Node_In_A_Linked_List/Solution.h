struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x)
	    : val(x), next(nullptr) {
	}
};

class Solution {
public:
	Solution() {
	}
	void deleteNode(ListNode *node);
	void deleteNode2(ListNode *node);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
