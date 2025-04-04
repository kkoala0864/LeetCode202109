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
	ListNode *partition(ListNode *head, int x);
	ListNode *partition2(ListNode *head, int x);
	ListNode *partition3(ListNode *head, int x);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
