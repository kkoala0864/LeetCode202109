#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

