#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int rob(vector<int>& nums);
	int rob2(vector<int>& nums);
	int rob3(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

