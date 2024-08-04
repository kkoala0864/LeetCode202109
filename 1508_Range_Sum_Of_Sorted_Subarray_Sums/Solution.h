#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int rangeSum(vector<int>& nums, int n, int left, int right);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

