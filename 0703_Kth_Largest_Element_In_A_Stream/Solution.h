#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::priority_queue;
using std::sort;

class KthLargest {
    public :
	    KthLargest(int k, vector<int>& nums) {
		    for (int i = 0 ; i < nums.size() ; ++i) {
			    maxHeap.emplace(nums[i]);
		    }
		    while (--k > 0) {
			    minHeap.emplace(maxHeap.top());
			    maxHeap.pop();
		    }
	    }

	    int add(int val) {
		    minHeap.emplace(val);
		    maxHeap.emplace(minHeap.top());
		    minHeap.pop();
		    return maxHeap.top();
	    }
    private :
	    priority_queue<int> maxHeap;
	    priority_queue<int, vector<int>, std::greater<int>> minHeap;
	    virtual ~KthLargest() {}
	    KthLargest& operator=(const KthLargest& source);
	    KthLargest(const KthLargest&);
};

