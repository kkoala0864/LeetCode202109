#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int minSubArrayLen(int target, vector<int>& nums);
	int minSubArrayLen2(int target, vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

