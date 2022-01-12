#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int eraseOverlapIntervals(vector<vector<int>>& intervals);
	int eraseOverlapIntervals2(vector<vector<int>>& intervals);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

