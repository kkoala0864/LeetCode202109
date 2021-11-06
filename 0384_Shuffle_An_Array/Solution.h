#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

class Solution {
    public :
	    Solution(vector<int>& nums) {
		    _nums = nums;
	    }

	    vector<int> reset() {
		return _nums;
	    }

	    vector<int> shuffle() {
		    vector<int> shuf = _nums;
		    for (int i = 0 ; i < shuf.size() ; ++i) {
			int idx = rand() % shuf.size();
			swap(shuf[i], shuf[idx]);
		    }
		    return shuf;
	    }
    private :
	vector<int> _nums;
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

