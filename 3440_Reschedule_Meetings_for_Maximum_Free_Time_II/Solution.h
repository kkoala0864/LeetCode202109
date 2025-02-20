#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
	    Solution() {}
	    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

