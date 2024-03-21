#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int numSubarraysWithSum(vector<int>& nums, int goal);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

