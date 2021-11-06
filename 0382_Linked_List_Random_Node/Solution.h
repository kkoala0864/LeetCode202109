#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public :
	    Solution(ListNode* head) {
		    ListNode* iter = head;
		    _size = 1;
		    while (iter->next) {
			    iter = iter->next;
			    ++_size;
		    }
		    iter->next = head;
		    cur = head;
	    }

	    int getRandom() {
		    int idx = rand() % _size;
		    while (idx >= 0) {
			cur = cur->next;
			--idx;
		    }
		    return cur->val;
	    }
    private :
	    ListNode* cur;
	    int _size;
	    virtual ~Solution() {}
	    Solution& operator=(const Solution& source);
	    Solution(const Solution&);
};

