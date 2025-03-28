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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
	ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB);
	ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
