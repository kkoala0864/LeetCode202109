#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int findPeakElement(vector<int>& nums);
	int findPeakElement2(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

