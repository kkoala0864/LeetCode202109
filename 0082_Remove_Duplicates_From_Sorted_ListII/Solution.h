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
	ListNode *deleteDuplicates(ListNode *head);
	ListNode *deleteDuplicates2(ListNode *head);
	ListNode *deleteDuplicates3(ListNode *head);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
