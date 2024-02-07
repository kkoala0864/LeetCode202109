#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

