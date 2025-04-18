struct ListNode
{
	int val;
	ListNode *next;
	ListNode()
	    : val(0), next(nullptr) {
	}
	ListNode(int x)
	    : val(x), next(nullptr) {
	}
	ListNode(int x, ListNode *next)
	    : val(x), next(next) {
	}
};

class Solution {
public:
	Solution() {
	}
	ListNode *removeElements(ListNode *head, int val);
	ListNode *removeElements2(ListNode *head, int val);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
