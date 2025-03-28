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
	ListNode *detectCycle(ListNode *head);
	ListNode *detectCycle2(ListNode *head);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
