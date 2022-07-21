struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public :
        Solution() {}
	ListNode* reverseBetween(ListNode* head, int left, int right);
	ListNode* reverseBetween2(ListNode* head, int left, int right);
	ListNode* reverseBetween3(ListNode* head, int left, int right);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

