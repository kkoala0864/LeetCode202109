#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

