#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int numberOfArithmeticSlices(vector<int>& nums);
	int Standard(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

